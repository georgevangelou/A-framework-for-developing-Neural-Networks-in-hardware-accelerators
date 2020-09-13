print("This script transforms a simple format of the Neural Network model into a file readable by C/C++ containing the weights of the NN.")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")

# This script transforms a simple format of the Neural Network model into a file readable by C/C++ containing the weights of the NN

# Dependencies
import numpy as np

# Array parser (1D)
def declare_array_1D(array_type, name, array_1D):
    N = len(array_1D)
    txt = array_type + " " + name + "[" + str(N) + "] = {"
    for i in range(N):
        txt += str(array_1D[i])
        if i != N - 1:
            txt += ","
        else:
            txt += "};\n\n"
    return txt

# Array parser (2D)
def declare_array_2D(array_type, name, array_2D):
    rows = len(array_2D)
    cols = len(array_2D[0])
    txt = array_type + " " + name + "[" + str(rows) + "][" + str(cols) + "] = {\n"
    for i in range(rows):
        txt += "{"
        for j in range(cols):
            txt += str(array_2D[i][j])
            if j != cols - 1:
                txt +=  ","
            elif j == cols - 1 and i != rows - 1:
                txt += "},\n"
    txt += "}};\n\n"
    return txt

# Array parser (4D)
def declare_array_4D(array_type, name, array_4D):
    dim1 = len(array_4D)
    dim2 = len(array_4D[0])
    dim3 = len(array_4D[0][0])
    dim4 = len(array_4D[0][0][0])
    txt = array_type + " " + name + "[" + str(dim1) + "][" + str(dim2) + \
        "][" + str(dim3) + "][" + str(dim4) + "] = {\n"
    for i in range(dim1):
        txt += "{"
        for j in range(dim2):
            txt += "{"
            for k in range(dim3):
                txt += "{"
                for l in range(dim4):
                    txt += str(array_4D[i][j][k][l])
                    if l != dim4 - 1:
                        txt += ","
                    else:
                        txt += "}"
                if k != dim3 - 1:
                    txt += ","
                else:
                    txt += "}"
            if j != dim2 - 1:
                txt += ",\n"
            else:
                txt += "}"
        if i != dim1 - 1:
            txt += ",\n\n"
        else:
            txt += "};\n\n"
    return txt

# Array to weights
def to_4D_weights(filter_dim, array_2D):
    rows = len(array_2D)
    cols = len(array_2D[0])
    filter_size = filter_dim * filter_dim
    
    neurons = rows  #dim1
    input_fms = (cols - 1) / (filter_size)  #dim2=filters/neuron
    dim3 = filter_dim
    dim4 = filter_dim

    weights = []
    biases = []
    for i in range(rows):
        filter_row = []
        filt = []
        filts = []
        for j in range(cols):
            if j != cols - 1:
                filter_row.append(array_2D[i][j])
            else:
                biases.append(array_2D[i][j])
                
            if (j+1) % filter_dim == 0:     #new row
                filt.append(filter_row)
                filter_row = []
            if (j+1) % filter_size == 0:    #new filter
                filts.append(filt)
                filt = []
        weights.append(filts)        
    return weights, biases


def split_dense(array_2D):
    rows = len(array_2D)
    cols = len(array_2D[0])

    weights = []
    biases = []
    for i in range(rows):
        weight_row = []
        for j in range(cols-1):
            weight_row.append(array_2D[i][j])
        biases.append(array_2D[i][cols-1])
        weights.append(weight_row)
    return weights, biases


FILTER_DIM = 3

inp_file = "generated/ER_simple.nnet"
print('Reading file "{}" to create "weights.h" file...'.format(inp_file)) 
with open(inp_file, 'r') as f: text = f.read()

temp = text.replace("[", "").replace("]", "").replace("\n", " ").split("#")
conv_1  = np.fromstring(temp[0], sep=' ').reshape(6, 10)  # 6 neurons and 1*9+1=10 elements per neuron
conv_2  = np.fromstring(temp[1], sep=' ').reshape(16, 55) #16 neurons and 6*9+1=55 elements per neuron

'''
dense_1 = np.fromstring(temp[2], sep=' ').reshape(120, 577)
dense_2 = np.fromstring(temp[3], sep=' ').reshape(84, 121)
dense_3 = np.fromstring(temp[4], sep=' ').reshape(10, 85)
'''

dense_1 = np.fromstring(temp[2], sep=' ').reshape(577, 120).transpose()
dense_2 = np.fromstring(temp[3], sep=' ').reshape(121, 84).transpose()
dense_3 = np.fromstring(temp[4], sep=' ').reshape(85, 10).transpose()


conv_weights1, conv_b1 = to_4D_weights(FILTER_DIM,conv_1)
conv_weights2, conv_b2 = to_4D_weights(FILTER_DIM,conv_2)
dense_weights1, dense_b1 = split_dense(dense_1)
dense_weights2, dense_b2 = split_dense(dense_2)
dense_weights3, dense_b3 = split_dense(dense_3)
with open("generated/weights.h", 'w') as f:
    f.write('#include "dimensions.h"\n\n')
    f.write(declare_array_4D("float", "conv_1_weights", conv_weights1))
    f.write(declare_array_1D("float", "conv_1_biases", conv_b1))
    f.write(declare_array_4D("float", "conv_2_weights", conv_weights2))
    f.write(declare_array_1D("float", "conv_2_biases", conv_b2))
    f.write(declare_array_2D("float", "dense_1_weights", dense_weights1))
    f.write(declare_array_1D("float", "dense_1_biases", dense_b1))
    f.write(declare_array_2D("float", "dense_2_weights", dense_weights2))
    f.write(declare_array_1D("float", "dense_2_biases", dense_b2))
    f.write(declare_array_2D("float", "dense_3_weights", dense_weights3))
    f.write(declare_array_1D("float", "dense_3_biases", dense_b3))

print('File "weights.h" successfully created.\n') 
