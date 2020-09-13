print("Modelling and training of a LeNet-5 implementation.")
print("Authors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n")

# Also check: https://colab.research.google.com/drive/1CVm50PGE4vhtB5I_a_yc4h5F-itKOVL9#scrollTo=IZhNBCFylP0s

# Dependencies
#from requests import get
import gzip
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
import keras
import keras.layers as layers
from keras.models import Sequential
from keras.preprocessing.image import ImageDataGenerator
from keras.utils.np_utils import to_categorical
from keras.callbacks import TensorBoard

# Constants
VALIDATION_RATIO = 0.2
EPOCHS = 10
BATCH_SIZE = 128
DESTINATION_FOLDER = "generated/"


# Downloads specified file
def download_file(url, file_name):
    with open(file_name, "wb") as file:
        response = get(url)
        file.write(response.content)


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


#Shows all training images
def display_image(position):
    image = train['features'][position].squeeze()
    plt.title('Example %d. Label: %d' % (position, train['labels'][position]))
    plt.imshow(image, cmap=plt.cm.gray_r)
    plt.show()


# Definition of LeNet-5 Neural Network
def build_lenet():
    model = keras.Sequential()

    model.add(layers.Conv2D(filters=6, kernel_size=(3, 3), 
                    activation='relu', input_shape=(32,32,1)))  # Convolutional Layer 1
    model.add(layers.AveragePooling2D())                        # Average Pooling Layer 1
    model.add(layers.Conv2D(filters=16, kernel_size=(3, 3), 
                    activation='relu'))                         # Convolutional Layer 2
    model.add(layers.AveragePooling2D())                        # Average Pooling Layer 2
    model.add(layers.Flatten())                                 # Flatenning Layer
    model.add(layers.Dense(units=120, activation='relu'))       # Fully Connected Layer 1
    model.add(layers.Dense(units=84, activation='relu'))        # Fully Connected Layer 2
    model.add(layers.Dense(units=10, activation = 'softmax'))   # Fully Connected Layer 3
    model.summary()
    model.compile(loss=keras.losses.categorical_crossentropy, 
            optimizer=keras.optimizers.Adam(), metrics=['accuracy'])
    return model
    


# Downloads all Mnist dataset files
def download_Mnist_dataset():
    download_file('http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz',
                'train-images-idx3-ubyte.gz')
    download_file('http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz',
                'train-labels-idx1-ubyte.gz')
    download_file('http://yann.lecun.com/exdb/mnist/t10k-images-idx3-ubyte.gz',
                't10k-images-idx3-ubyte.gz')
    download_file('http://yann.lecun.com/exdb/mnist/t10k-labels-idx1-ubyte.gz',
                't10k-labels-idx1-ubyte.gz')


# Loading the dataset
train = {}
test = {}

train['features'], train['labels'] = read_mnist('../0.Resources/train-images-idx3-ubyte.gz', '../0.Resources/train-labels-idx1-ubyte.gz')
test['features'], test['labels'] = read_mnist('../0.Resources/t10k-images-idx3-ubyte.gz', '../0.Resources/t10k-labels-idx1-ubyte.gz')

validation = {}
train['features'], validation['features'], train['labels'],validation['labels'] = train_test_split(
                                    train['features'], train['labels'], test_size=VALIDATION_RATIO, random_state=0)


# Lenet used 32x32 images, so we need to apply zero padding to our 28x28 images 
train['features']      = np.pad(train['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
validation['features'] = np.pad(validation['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
test['features']       = np.pad(test['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')


# Implementing the network
model = build_lenet()


# Training the network
##to_categorical = one_hot encoding
X_train, y_train = train['features'], to_categorical(train['labels'])
X_validation, y_validation = validation['features'], to_categorical(validation['labels'])

train_generator = ImageDataGenerator().flow(X_train, 
                        y_train, batch_size=BATCH_SIZE)
validation_generator = ImageDataGenerator().flow(X_validation, 
                        y_validation, batch_size=BATCH_SIZE)

steps_per_epoch = X_train.shape[0]//BATCH_SIZE
validation_steps = X_validation.shape[0]//BATCH_SIZE
model.fit_generator(train_generator, steps_per_epoch=steps_per_epoch, 
                    epochs=EPOCHS, validation_data=validation_generator, 
                    validation_steps=validation_steps, shuffle=True)


# Evaluating the model
score = model.evaluate(test['features'], to_categorical(test['labels']))
print('Test loss:', score[0])
print('Test accuracy:', score[1])


# Saving all data of the model
model.save(DESTINATION_FOLDER + 'LeNet.h5')
f = open(DESTINATION_FOLDER + 'LeNet_architecture.json','w')
f.write(model.to_json())
f.close()
model.save_weights(DESTINATION_FOLDER + 'LeNet_weights.h5')
