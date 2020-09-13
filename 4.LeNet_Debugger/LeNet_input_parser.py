print("This script is used to create an inputs.h file to by used by our C/C++ implementation of evaluation")
print("DEPRECATED. Now the functionality of the network by inputting images and outputting labels is done with the Vivado Testbench")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")

VALIDATION_RATIO = 0.2
DESTINATION_FOLDER = "generated/"
some_labels = [7,4,5,7,1,7,6,1,8,1,9,0,7,8,3,9,5,0,6,8,1,7,0,4,8,7,7,8,4,8,1,6,9,8,6,1,7,4,2,9,8,9,5,6,1,6,8,5,5,8,7,6,7,1,3,2,8,5,7,2,8,9,3,6,5,9,0,9,3,5,5,4,8,5,6,4,0,2,6,2,0,0,8,6,4,7,9,6,4,5,0,3,8,4,5,7,0,8,6,2,0,0,1,5,6,7,3,9]

ind = int(input("SET THE IMAGE INDEX: "))
if ind<len(some_labels):
	print("--> ITS VALUE IS:",some_labels[ind])
print("NOW EXTRACTING THE IMAGE...")


import gzip
import numpy as np
from sklearn.model_selection import train_test_split


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

def declare_array_2D(array_type, name, array_2D, add_extra_dimension=False):
    rows = len(array_2D)
    cols = len(array_2D[0])
    
    foo1_evg = '' #gia auto insertion extra dimension 
    foo2_evg = '' #gia auto insertion extra dimension 
    if add_extra_dimension==True:  #gia auto insertion extra dimension 
        name += "[1]"
        foo1_evg = '{'
        foo2_evg = '}'

    txt = array_type + " " + name + "[" + str(rows) + "][" + str(cols) + "] ="+foo1_evg+" {\n"
    for i in range(rows):
        txt += "{"
        for j in range(cols):
            txt += str(array_2D[i][j])
            if j != cols - 1:
                txt +=  ","
            elif j == cols - 1 and i != rows - 1:
                txt += "},\n"
    txt += "}}"+foo2_evg+";\n\n"
    return txt

#1. Loading the dataset
train = {}
test = {}
validation = {}

train['features'], train['labels'] = read_mnist('../0.Resources/train-images-idx3-ubyte.gz', '../0.Resources/train-labels-idx1-ubyte.gz')
test['features'], test['labels'] = read_mnist('../0.Resources/t10k-images-idx3-ubyte.gz', '../0.Resources/t10k-labels-idx1-ubyte.gz')
train['features'], validation['features'], train['labels'],validation['labels'] = train_test_split(train['features'],
                                    train['labels'],
                                    test_size=VALIDATION_RATIO,
                                    random_state=0)

#2. Lenet used 32x32 images, so we need to apply zero padding to our 28x28 images 
train['features']      = np.pad(train['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
validation['features'] = np.pad(validation['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
test['features']       = np.pad(test['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')

train['features']=train['features'].squeeze()
validation['features']=validation['features'].squeeze()
test['features']=test['features'].squeeze()

#with open("../3.LeNet_ER_source_code/inputs.h", 'w') as f:
with open(DESTINATION_FOLDER + "inputs.h", 'w') as f:
    f.write("/* This is the image with index={} */ \n".format(ind))
    f.write(declare_array_2D("float", "train_features", train['features'][ind], add_extra_dimension=True) )
    f.write("/*\n")
    f.write(declare_array_2D("char", "validation_features", validation['features'][ind]))
    f.write(declare_array_2D("char", "test_features", test['features'][ind]))
    f.write(declare_array_1D("char", "train_labels", train['labels']))
    f.write(declare_array_1D("char", "validation_labels", validation['labels']))
    f.write(declare_array_1D("char", "test_labels", test['labels']))
    f.write("*/")

print("DONE.\n")
