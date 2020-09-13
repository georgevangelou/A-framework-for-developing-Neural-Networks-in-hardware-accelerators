print("This program runs our LeNet-5 Python implementation and calculates its average runtime.")
print("Authors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n")

# Dependencies
import gzip
import numpy as np
import keras
import tensorflow as tf
from keras.models import model_from_json
from keras import backend as K
import json
import time


# Reads downloaded Mnist dataset files
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


# Gets system time in millis
def get_current_millis():
    return int(round(time.time() * 1000)) # seconds --> milliseconds


# Configures session to run only on one thread
session_conf = tf.ConfigProto( \
      intra_op_parallelism_threads=1, \
      inter_op_parallelism_threads=1, \
      allow_soft_placement = True, \
      device_count = {'CPU':1})
sess = tf.Session(config=session_conf)
K.set_session(sess)


# Loading the dataset
train = {}
test = {}

train['features'], train['labels'] = read_mnist('../0.Resources/train-images-idx3-ubyte.gz', '../0.Resources/train-labels-idx1-ubyte.gz')
test['features'], test['labels'] = read_mnist('../0.Resources/t10k-images-idx3-ubyte.gz', '../0.Resources/t10k-labels-idx1-ubyte.gz')


# Lenet used 32x32 images, so we need to apply zero padding to our 28x28 images 
train['features']      = np.pad(train['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
test['features']       = np.pad(test['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')


# Load model
arch = open('generated/LeNet_architecture.json').read()
model = model_from_json(arch)
model.load_weights('generated/LeNet_weights.h5')
arch = json.loads(arch)


# Calculate average LeNet prediction time in millis
acc = 0.0
num_of_images = len(test['features'])
print("\nNow started estimating average runtime for {} images...".format(num_of_images))
for i in range(num_of_images):
    img = test['features'][i].reshape((1,32,32,1))
    start = get_current_millis()
    model.predict_classes(img)
    acc += get_current_millis() - start
print("Average LeNet prediction time for each image: {:.3f} milliseconds".format(float(acc)/num_of_images))

#start = get_current_millis()
#model.predict_classes(train['features'][0].reshape((1,32,32,1)))
#print(get_current_millis()-start)
