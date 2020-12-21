import numpy as np
import argparse
from utils import *


def get_data(dataset):
    datasets = ['D1', 'D2']
    assert dataset in datasets, "Dataset {dataset} not supported. Supported datasets {datasets}"
    X_train = np.loadtxt(f'data/{dataset}/training_data')
    Y_train = np.loadtxt(f'data/{dataset}/training_labels', dtype=int)
    X_test = np.loadtxt(f'data/{dataset}/test_data')
    Y_test = np.loadtxt(f'data/{dataset}/test_labels', dtype=int)

    return X_train, Y_train, X_test, Y_test

class LogisticRegression:
    def __init__(self, C, D):
        """
        C - number of classes
        D - number of features
        """
        self.C = C
        self.D = D
        self.weights = np.random.rand(D, C)

    def softmax(self, X):
        """
        :param X: (N, D) array
        :return: softmax for given X and current weights
        """
        # TODO: Compute Softmax
        x = np.dot(X,self.weights)
        Z = np.exp(x).T / np.sum(np.exp(x), axis=1)
        return Z.T
        # END TODO

    def predict(self, X):
        """
        :param X: numpy array of shape (N, D) corresponding to inputs data
        :return: numpy array of shape (N, 1) corresponding to predicted labels
        """
        # TODO: Return a (N, 1) numpy array of predictions.
        return np.argmax(self.softmax(X), axis=1)
        # END TODO

    def train(self, X, Y, lr=0.1, max_iter=500):
        Y = one_hot_encode(Y, np.unique(Y))
        for i in range(max_iter):
            # TODO: Update the weights using a single step of gradient descent. You are not allowed to use loops here.
            gradient = np.dot(np.transpose(X), self.softmax(X) - Y)/Y.shape[0]
            self.weights = self.weights - lr * gradient
            # END TODO

            # TODO: Stop the algorithm if the norm of the gradient falls below 1e-4
            if np.sqrt(np.sum(gradient**2)) <= 1e-4:
                break
            # End TODO

    def eval(self, X, Y):
        """
        X - numpy array of shape (N, D) corresponding to inpus data
        Y - numpy array of shape (N, 1) corresponding to true labels
        """
        preds = self.predict(X)
        accuracy = ((preds == Y).sum()) / len(preds)
        return accuracy


if __name__ == '__main__':
    np.random.seed(335)

    X_train, Y_train, X_test, Y_test = get_data("D1")

    C = max(np.max(Y_train), np.max(Y_test)) + 1
    D = X_train.shape[1]

    lr = LogisticRegression(C, D)
    lr.train(X_train, Y_train)
    acc = lr.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')
