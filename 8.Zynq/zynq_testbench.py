print("This program sends a user defined number of images to the Zynq board" + \
      " for evaluation.")
print("DISCLAIMER: The Zynq board should be already running the ER_lenet" + \
      " code before running this program.")
print("\nAuthors: George Evangelou & Nick Roussos")
print("Date: 2019-2020")
print("Electrical and Computer Engineering Department, University of Patras, Greece\n\n")

# This is an application that sends data to the ZYNQ board (using our custom protocol) and
# performs evaluation.

##DATA FORMAT OF THE CUSTOM COMMUNICATION PROTOCOL
##
##HOST-PC:
##<SOH><STX>label1<CR>
##image1_pixel1<CR>
##image1_pixel2<CR>
##...
##image1_pixel1024<CR>
##<ETX>
##(wait for Zynq response)
##<STX>label2<CR>
##image2_pixel1<CR>
##image2_pixel2<CR>
##...
##image2_pixel1024<CR>
##<ETX>
##(wait for Zynq response)
##...
##<STX>labeln<CR>
##imagen_pixel1<CR>
##imagen_pixel2<CR>
##...
##imagen_pixel1024<CR>
##<ETX>
##(wait for Zynq response)
##<EOT>
##
##
##ZYNQ RESPONSES:
##<ACK> when recognized label matches the true label
##<NACK> otherwise

from requests import get
import gzip
import numpy as np
import matplotlib.pyplot as plt
import serial
import time


ZYNQ_PORT = "COM5"
BAUD_RATE = 115200

START_CHAR = b'\x01'        #SOH
IMAGE_START_CHAR = b'\x02'  #STX
SEPARATION_CHAR = b'\r'     #CR
IMAGE_END_CHAR = b'\x03'    #ETX
END_CHAR = b'\x04'          #EOT
ACK_CHAR = b'\x06'          #ACK
NACK_CHAR = b'\x07'         #BEL (used as NACK)

#DEBUG
f = open("dump.txt", 'wb')

#Downloads specified file
def download_file(url, file_name):
    with open(file_name, "wb") as file:
        response = get(url)
        file.write(response.content)

#Reads downloaded Mnist dataset files
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

#Downloads all Mnist dataset files
def download_Mnist_dataset():
    download_file('http://yann.lecun.com/exdb/mnist/train-images-idx3-ubyte.gz',
                'train-images-idx3-ubyte.gz')
    download_file('http://yann.lecun.com/exdb/mnist/train-labels-idx1-ubyte.gz',
                'train-labels-idx1-ubyte.gz')
    download_file('http://yann.lecun.com/exdb/mnist/t10k-images-idx3-ubyte.gz',
                't10k-images-idx3-ubyte.gz')
    download_file('http://yann.lecun.com/exdb/mnist/t10k-labels-idx1-ubyte.gz',
                't10k-labels-idx1-ubyte.gz')

#Config serial port to 8N1
def serial_init():
    ser = serial.Serial(ZYNQ_PORT);
    ser.baudrate = BAUD_RATE
    ser.bytesize = serial.EIGHTBITS;
    ser.parity = serial.PARITY_NONE;
    ser.stopbits = serial.STOPBITS_ONE;

    return ser

#Single image transmission
def transmit_image(ser, image, label):
    #indicate image start
    ser.write(IMAGE_START_CHAR)
    f.write(IMAGE_START_CHAR)

    #first byte is the true label of the image
    ser.write(str(label).encode())  #convert to ASCII
    f.write(str(label).encode())
    ser.write(SEPARATION_CHAR)
    f.write(SEPARATION_CHAR)
    for i in range(len(image)):
        for j in range(len(image[0])):
            ser.write(str(image[i][j]).encode()) #convert to ASCII
            f.write(str(image[i][j]).encode())
            ser.write(SEPARATION_CHAR)
            f.write(SEPARATION_CHAR)
            #time.sleep(0.001)

    #indicate the end of the image
    ser.write(IMAGE_END_CHAR)
    f.write(IMAGE_END_CHAR)


def printProgressBar (iteration, total, prefix = 'Progress:', suffix = 'Complete', decimals = 1, length = 50, fill = '█'):
    """
    Call in a loop to create terminal progress bar
    @params:
    iteration - Required : current iteration (Int)
    total - Required : total iterations (Int)
    prefix - Optional : prefix string (Str)
    suffix - Optional : suffix string (Str)
    decimals - Optional : positive number of decimals in percent complete (Int)
    length - Optional : character length of bar (Int)
    fill - Optional : bar fill character (Str)
    """

    percent = ("{0:." + str(decimals) + "f}").format(100 * (iteration / float(total)))
    filledLength = int(length * iteration // total)
    bar = fill * filledLength + '-' * (length - filledLength)
    print('\r%s |%s| %s%% %s' % (prefix, bar, percent, suffix), end = '\r')
    # Print a new line after completion
    if iteration == total:
        print("")

def evaluate_lenet(ser, images, labels, num_of_images):
    correct = 0
    imagesCompleted = 0
    
    #indicate start of transmission
    ser.write(START_CHAR)
    f.write(START_CHAR)
    for i in range(num_of_images):
        transmit_image(ser, images[i], labels[i])

        #wait for Zynq response
        byte_in = ser.read()
        imagesCompleted += 1
        if(byte_in == ACK_CHAR):
            correct +=1

        #print("\rCorrect: {:d}/{:d}".format(correct,num_of_images))
        printProgressBar(imagesCompleted, num_of_images)

    #indicate end of transmission
    ser.write(END_CHAR)
    f.write(END_CHAR)
    return correct


#Read number of images to transmit
num_of_images = int(input("Select the number of test images (1 - 10000)" + \
                          " to be transmitted to the Zynq board: "))
while (num_of_images<1 or num_of_images > 10000):
    print("Incorrect number of images provided")
    num_of_images = int(input("Incorrect number of images provided. Please try again: "))
print("Now running...")

#Loading the dataset
train = {}
test = {}

train['features'], train['labels'] = read_mnist('../0.Resources/train-images-idx3-ubyte.gz', '../0.Resources/train-labels-idx1-ubyte.gz')
test['features'], test['labels'] = read_mnist('../0.Resources/t10k-images-idx3-ubyte.gz', '../0.Resources/t10k-labels-idx1-ubyte.gz')


#Lenet used 32x32 images, so we need to apply zero padding to our 28x28 images 
train['features']   = np.pad(train['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')
test['features']    = np.pad(test['features'], ((0,0),(2,2),(2,2),(0,0)), 'constant')

#Eliminate dimension which consists only of 1 element
train['features'] = train['features'].squeeze()
test['features']  = test['features'].squeeze()

#Transmit images to the Zynq board
ser = serial_init()

correct = evaluate_lenet(ser, test['features'], test['labels'], num_of_images)

ser.close()
f.close()

#Output HW LeNet test accuracy
accuracy = float(correct)/num_of_images
print("Accuracy: {:.2f}% @ {:d} images".format(accuracy*100, num_of_images))
input()
