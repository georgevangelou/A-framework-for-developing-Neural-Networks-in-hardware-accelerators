print("This is a simple script to dump Keras model into simple format suitable for porting into pure C/C++ model.")
print("This version uses user-input for configuration.")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")

# This is a simple script to dump Keras model into simple format suitable for porting into pure C/C++ model.
# This version uses user-input for configuration.

# Dependencies
import numpy as np
np.random.seed(1337)
from keras.models import Sequential, model_from_json
import json
import argparse

# Parsing console input
np.set_printoptions(threshold=np.inf)
parser = argparse.ArgumentParser(description='This is a simple script to dump Keras model into simple format suitable for porting into pure C++ model')
parser.add_argument('-a', '--architecture', help="JSON with model architecture", required=True)
parser.add_argument('-w', '--weights', help="Model weights in HDF5 format", required=True)
parser.add_argument('-o', '--output', help="Ouput file name", required=True)
parser.add_argument('-v', '--verbose', help="Verbose", required=False)
args = parser.parse_args()
print('Read architecture from', args.architecture)
print('Read weights from', args.weights)
print('Writing to', args.output)

# Parsing architecture and model
arch = open(args.architecture).read()
model = model_from_json(arch)
model.load_weights(args.weights)
#model.compile(loss='categorical_crossentropy', optimizer='adadelta')
arch = json.loads(arch)


# Creating output file
with open(args.output, 'w') as fout:
    fout.write('layers ' + str(len(model.layers)) + '\n')

    layers = []
    layers_names = []
    layers_json = arch["config"]["layers"]
    total_index = -1
    for index, layer in enumerate(layers_json):
        total_index += 1
        print("Index: {} and layer name is: {} ".format(index, layer["class_name"]))

        name = layer["class_name"]
        layers.append(layer)
        layers_names.append(name)
        fout.write('layer ' + str(total_index) + ' ' + name + '\n')
    
        if name=="Conv2D":
            W = model.layers[index].get_weights()[0]
            print(W)
            fout.write(str(W.shape[0]) + ' ' + str(W.shape[1]) + ' ' + str(W.shape[2]) + ' ' + str(W.shape[3]) + ' ' + layer['config']['padding'] + '\n')
            for i in range(W.shape[0]):
                for j in range(W.shape[1]):
                    for k in range(W.shape[2]):
                        fout.write(str(W[i][j][k]) + '\n')
            fout.write(str(model.layers[index].get_weights()[1]) + '\n')

            total_index+=1
            fout.write('layer ' + str(total_index) + ' ' + "Activation" + '\n')
            fout.write(layer['config']['activation'] + '\n')

        elif name=="Dense":
            W = model.layers[index].get_weights()[0]
            fout.write(str(W.shape[0]) + ' ' + str(W.shape[1]) + '\n')
            for w in W:
                fout.write(str(w) + '\n')
            fout.write(str(model.layers[index].get_weights()[1]) + '\n')

            total_index+=1
            fout.write('layer ' + str(total_index) + ' ' + "Activation" + '\n')
            fout.write(layer['config']['activation'] + '\n')

        elif name=="AveragePooling2D": 
            fout.write(str(layer['config']['pool_size'][0]) + ' ' + str(layer['config']['pool_size'][1]) + '\n')
        elif name=="Flatten": 
            pass
        else:
            print("WARNING: Layer not recognized: " + name)
            


