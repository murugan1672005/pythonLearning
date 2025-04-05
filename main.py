import numpy as np 
class Network(object):
    def __init__(self,*args,**kargs):
         self.biases = args
         self.weights = kargs
    def feed_forward(self,a):
        for b,w in zip(biases,weights):
            a = sigmoid(np.dot(w,a)+b)
        return a 
