print("This is a simple script to dump Keras model into simple format suitable for porting into pure C/C++ model.")
print("This version uses hardcoded-input for configuration.")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")

# This is a simple script to dump Keras model into simple format suitable for porting into pure C/C++ model.
# This version uses hardcoded-input for configuration.

# Dependencies
from keras.models import Sequential, model_from_json
import json
import matplotlib.pyplot as plt

# Parsing architecture and model
arch = open('LeNet_architecture.json').read()
model = model_from_json(arch)
model.load_weights('LeNet_weights.h5')
#model.compile(loss='categorical_crossentropy', optimizer='adadelta')
arch = json.loads(arch)

# Creating output file
with open('generated/ER_simple.nnet', 'w') as fout:
    #fout.write('layers ' + str(len(model.layers)) + '\n')

    layers = []
    layers_names = []
    layers_json = arch["config"]["layers"]
    total_index = -1
    CONV_WEIGHTS = []
    for index, layer in enumerate(layers_json):
        total_index += 1
        #print("Index: {} and layer name is: {} ".format(index, layer["class_name"]))

        name = layer["class_name"]
        layers.append(layer)
        layers_names.append(name)
        #fout.write('layer ' + str(total_index) + ' ' + name + '\n')
    
        if name=="Conv2D":
            W = model.layers[index].get_weights()[0]
            CONV_WEIGHTS.append(W)
            '''
            print("\n\nWeights for this conv are:\n")
            print(W)
            print("\nShape is:\n")
            print(str(W.shape[0]) + ' ' + str(W.shape[1]) + ' ' + str(W.shape[2]) + ' ' + str(W.shape[3]))
            '''
            #[ker1,ker2,kernel,neuron]
            #fout.write(str(W.shape[0]) + ' ' + str(W.shape[1]) + ' ' + str(W.shape[2]) + ' ' + str(W.shape[3]) + ' ' + layer['config']['padding'] + '\n')

            for n in range(W.shape[3]):
                #NEW NEURON
                fout.write("[")
                for k in range(W.shape[2]):
                    #NEW KERNEL
                    fout.write("[")
                    for i in range(W.shape[0]):
                        for j in range(W.shape[1]):
                            fout.write( str(W[i][j][k][n]) )
                            fout.write(" ")
                    fout.write("]")
                fout.write(" [" + str(model.layers[index].get_weights()[1][n]) + "]") #the biases
                fout.write("]\n")
            total_index+=1
            #fout.write('layer ' + str(total_index) + ' ' + "Activation" + '\n')
            #fout.write(layer['config']['activation'] + '\n')
            fout.write("#")

        elif name=="Dense":
            W = model.layers[index].get_weights()[0]
            #fout.write(str(W.shape[0]) + ' ' + str(W.shape[1]) + '\n')
            for w in W:
                fout.write(str(w) + '\n')
            fout.write(str(model.layers[index].get_weights()[1]) + '\n')

            total_index += 1
            #fout.write('layer ' + str(total_index) + ' ' + "Activation" + '\n')
            #fout.write(layer['config']['activation'] + '\n')
            fout.write("#")

        elif name=="AveragePooling2D": 
            fout.write(str(layer['config']['pool_size'][0]) + ' ' + str(layer['config']['pool_size'][1]) + '\n')
        elif name=="Flatten": 
            pass
        else:
            print("WARNING: Layer not recognized: " + name)

NEURONS = 16
KERNELS = 6
x1w = CONV_WEIGHTS[1]

'''
for n in range(NEURONS):
    print("\n\nNeuron: ",n )
    for k in range(KERNELS):
        print("\nKernel: ",k )
        print(x1w[:,:,k,n])
'''

'''
#for i in range(0,NEURONS):
for j in range(0,KERNELS):
    plt.subplot(2,3,j+1)
    #[ker1,ker2,kernel,neuron]
    plt.imshow(x1w[:,:,j,0],interpolation="nearest",cmap="gray")
plt.show()'''