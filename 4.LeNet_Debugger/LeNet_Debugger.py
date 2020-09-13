print("This script produces the output of each layer of the our LeNet-5 Python implementation.")
print("These results can then be used to debug layer functionality in our LeNet-5 C/C++ implementation.")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")

import gzip
import numpy as np
import keras.layers as layers
from keras.models import load_model, model_from_json, Sequential
from keras.utils.np_utils import to_categorical
from keras import backend as K
from sklearn.model_selection import train_test_split
from requests import get

SOURCE_FOLDER = "../1.LeNet_in_python/generated/"
VALIDATION_RATIO = 0.2

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

model = load_model(SOURCE_FOLDER + "LeNet.h5")

train = {}
test = {}
train['features'], train['labels'] = read_mnist('../0.Resources/train-images-idx3-ubyte.gz', '../0.Resources/train-labels-idx1-ubyte.gz')
test['features'], test['labels'] = read_mnist('../0.Resources/t10k-images-idx3-ubyte.gz', '../0.Resources/t10k-labels-idx1-ubyte.gz')
validation = {}
train['features'], validation['features'], train['labels'],validation['labels'] = train_test_split(train['features'], train['labels'],test_size=VALIDATION_RATIO, random_state=0)
train['features']      = np.pad(train['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
validation['features'] = np.pad(validation['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
test['features']       = np.pad(test['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
X_train, y_train = train['features'], to_categorical(train['labels'])
X_validation, y_validation = validation['features'], to_categorical(validation['labels'])
#score = model.evaluate(test['features'], to_categorical(test['labels']))
model.summary()

print("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$")
print("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n")

eikona = 0
LAYER = 8
#0:conv, 1:pooling, 2:conv, 3:pooling, 4:flatten, 5:dense, 6:dense, 7:dense
diastash_eikonwn = [30, 15, 13, 6]
outputnum = [6, 6, 16, 16, 120, 84, 10]
NAMES = ["CONV_1 OUTPUT", "POOLING_1 OUTPUT", "CONV_2 OUTPUT", "POOLING_2 OUTPUT", "FLATTEN OUTPUT", "DENSE_1 OUTPUT", "DENSE_2 OUTPUT", "DENSE_3 OUTPUT"]
inp = model.input        
inp = train['features'][eikona].reshape(1,32,32,1)                    

for L in range(LAYER):
    txt = "layeroutput"+str(L+1)+".txt"
    with open(txt,'w') as f:
        get_L_layer_output = K.function([model.layers[0].input], [model.layers[L].output])
        layer_output = get_L_layer_output(inp)[0][0]
        f.write( "This is " + str(NAMES[L]) + "\n")
        f.write( "=================================\n")
        if L<4:
            for a in range(outputnum[L]):
                f.write( "\n\n\nThis is NEURON(" + str(a) + ") OUTPUT :"  )
                for grammh in range(diastash_eikonwn[L]):
                    f.write('\n')
                    for stoixeio in range(diastash_eikonwn[L]):
                        f.write(str(layer_output[grammh][stoixeio][a]) + ' ')
        else:
            f.write('\n')
            f.write(str(layer_output) + ' ')
            '''
            for e in range(outputnum[L]):
                f.write('\n')
                f.write(str(layer_output[e]) + ' ')
            '''

print("Files ready.\n")



