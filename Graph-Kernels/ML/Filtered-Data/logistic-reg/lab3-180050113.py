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


def one_hot_encode(X, labels):
    '''
    Args:
    X - numpy array of shape (n_samples, 1)
    labels - list of all possible labels for current category

    Returns:
    X in one hot encoded format (numpy array of shape (n_samples, n_labels))
    '''
    X.shape = (X.shape[0], 1)
    newX = np.zeros((X.shape[0], len(labels)))
    label_encoding = {}
    for i, l in enumerate(labels):
        label_encoding[l] = i
    for i in range(X.shape[0]):
        newX[i, label_encoding[X[i, 0]]] = 1
    return newX


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
        w = self.weights
        # n_classes = self.C
        y = np.dot(X,w)
        y = np.exp(y)
        y = y/(np.sum(y,axis=1)).reshape(X.shape[0],1)
        # soft = (np.sum(np.exp(np.dot(X,w)),axis=1)/(np.sum(np.exp(np.dot(X,w))))).reshape(X.shape[0],1)
        return y
        # END TODO

    def predict(self, X):
        """
        :param X: numpy array of shape (N, D) corresponding to inpus data
        :return: numpy array of shape (N, 1) corresponding to predicted labels
        """
        # TODO: Return a (N, 1) numpy array of predictions.
        w = self.weights
        Y = np.dot(X,w)
        return np.argmax(Y,axis=1)
        # END TODO

    def train(self, X, Y, lr=0.3, max_iter=100):
        Y = one_hot_encode(Y, np.unique(Y))
        for i in range(max_iter):
            # TODO: Update the weights using a single step of gradient descent. You are not allowed to use loops here.
            w = self.weights
            m = X.shape[0]
            soft = self.softmax(X)
            # print(soft.shape)
            # sigma = 1/(1+np.exp(-1*np.dot(X,w)))
            dw = np.dot(X.T,(Y-soft))/m
            self.weights = w + lr*dw
            # END TODO

            # TODO: Stop the algorithm if the norm of the gradient falls below 1e-4
            dist = np.linalg.norm(dw)
            if(dist<0.0001):
                break
            # END TODO


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
