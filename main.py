import numpy as np

def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))

class Network(object):
    def __init__(self, biases, weights):
        self.biases = biases
        self.weights = weights

    def feed_forward(self, a):
        for b, w in zip(self.biases, self.weights):
            a = sigmoid(np.dot(w, a) + b)
        return a
