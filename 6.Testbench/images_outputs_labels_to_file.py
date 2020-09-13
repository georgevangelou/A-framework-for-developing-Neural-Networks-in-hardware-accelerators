print("This script inputs the dataset and the NN model and produces files with:")
print("- Images' features")
print("- (almost) Golden output per output layer per image")
print("- Images' labels")
print("in .dat files, which can be used by Vivado HLS.")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")


# This script inputs the dataset and the NN model and produces files with:
# - Images' features
# - (almost) Golden output per output layer per image
# - Images' labels
# in .dat files, which can be used by Vivado HLS.

NUM_OF_IMAGES = 10000

from requests import get
import gzip
import numpy as np
import gzip
import keras.layers as layers
from keras.models import load_model
from keras import backend as K


def download_file(url, file_name):
    with open(file_name, "wb") as file:
        response = get(url)
        file.write(response.content)

def read_mnist(images_path: str, labels_path: str):
    with gzip.open(labels_path, 'rb') as labelsFile:
        labels = np.frombuffer(labelsFile.read(), dtype=np.uint8, offset=8)

    with gzip.open(images_path,'rb') as imagesFile:
        length = len(labels)
        # Load flat 28x28 px images (784 px), and convert them to 28x28 px
        features = np.frombuffer(imagesFile.read(), dtype=np.uint8, offset=16) \
                        .reshape(length, 784) \
                        .reshape(length, 28, 28, 1)
    return features, labels

def save_inputs(filename, images_arr):
    height = images_arr.shape[1]
    width = images_arr.shape[2]
    with open(filename, 'w') as f:
        #f.write("{:<5} {:<5} {:<5} {:<5}\n".format("IMAGE","Y", "X", "PIXEL VALUE"))
        for img in range(NUM_OF_IMAGES):
            for y in range(height):
                for x in range(width):
                    f.write("{:d} {:d} {:d} {:d}\n".format(
                        img, y, x, images_arr[img][y][x]))
    print("Wrote inputs to file.")


def save_outputs(filename, model):
    get_L_layer_output = K.function([model.layers[0].input], [model.layers[-1].output])
    with open(filename, 'w') as f:
        for img in range(NUM_OF_IMAGES):
            inp = all_images['features'][img].reshape(1,32,32,1)
            layer_output = get_L_layer_output(inp)[0][0]
            for output in range(len(layer_output)):
                f.write("{:d} {:d} {:f}\n".format(img, output, layer_output[output]))
    print("Wrote golden outputs to file.")


def save_labels(filename, images_arr):
    with open(filename, "w") as f:
        mpla = 0
        lista = images_arr
        for i in range(len(lista['labels'])):
            mpla += 1
            f.write(str(mpla) + " " + str(lista['labels'][i]) + "\n")
    print("Wrote golden labels to file.")



# Load dataset
train = {}
test = {}

train['features'], train['labels'] = read_mnist('../0.Resources/train-images-idx3-ubyte.gz', '../0.Resources/train-labels-idx1-ubyte.gz')
test['features'], test['labels'] = read_mnist('../0.Resources/t10k-images-idx3-ubyte.gz', '../0.Resources/t10k-labels-idx1-ubyte.gz')

# Zero padding
train['features'] = np.pad(train['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
test['features'] = np.pad(test['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')

# Remove single dimensional entries
train['features'] = train['features'].squeeze()
test['features'] = test['features'].squeeze()

# Concatenate train and test images
all_images = {}
all_images['features'] = np.concatenate((test['features'], train['features']), axis=0)
all_images['labels'] = np.concatenate((test['labels'], train['labels']), axis=0)

# Load model
model = load_model("../1.LeNet_in_python/generated/LeNet.h5")


# Save file
save_inputs("generated/input.dat", all_images['features'])
save_outputs("generated/output_golden.dat", model)
save_labels("generated/labels_golden.dat", all_images)



    
