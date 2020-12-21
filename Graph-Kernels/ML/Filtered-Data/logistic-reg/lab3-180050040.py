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
    lenght = len(labels)
    nX = np.zeros((X.shape[0], lenght))
    label_encoding = {}
    for i, l in enumerate(labels):
        label_encoding[l] = i
    for i in range(X.shape[0]):
        nX[i, label_encoding[X[i, 0]]] = 1
    return nX


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
        v = X @ self.weights

        v -= np.max(v)
        j = np.max(v)
        # k = np.sum(j,axis=1)
        k = np.sum(np.exp(v),axis=1)
        ans = (np.exp(v).T / k).T
        # ans = (np.exp(z).T / k).T
        return ans
        # END TODO

    def predict(self, X):
        """
        :param X: numpy array of shape (N, D) corresponding to inpus data
        :return: numpy array of shape (N, 1) corresponding to predicted labels
        """
        # TODO: Return a (N, 1) numpy array of predictions.
        # a = self.softmax(X)
        # p = np.argmax(a,axis=1)
        # np.argmax(self.softmax(X),axis=1)
        return np.argmax(self.softmax(X),axis=1)
        # END TODO

    def train(self, X, Y, lr=0.4, max_iter=200):
        Y = one_hot_encode(Y, np.unique(Y))
        n = X.shape[0]
        for i in range(max_iter):
            # TODO: Update the weights using a single step of gradient descent. You are not allowed to use loops here.
            # s = np.dot(X,self.weights)
            a = self.softmax(X)
            f = (-1 / n)
            z = (Y - a)
            t = X.T
            p = np.dot(t,z)
            b = f * p
            g = lr * b
            # self.weights -= lr * g
            self.weights -= g
            # END TODO

            # TODO: Stop the algorithm if the norm of the gradient falls below 1e-4
            j = np.linalg.norm(b)
            if j < 1e-4:
                print("break",i)
                break
            # End TODO

    def eval(self, X, Y):
        """
        X - numpy array of shape (N, D) corresponding to inpus data
        Y - numpy array of shape (N, 1) corresponding to true labels
        """
        a = self.predict(X)
        sum1 = ((a == Y).sum())
        lenght = len(a)
        #accuray
        acc = sum1 / lenght
        return acc


if __name__ == '__main__':
    np.random.seed(335)

    X_train, Y_train, X_test, Y_test = get_data("D1")

    C = max(np.max(Y_train), np.max(Y_test)) + 1
    D = X_train.shape[1]

    lr = LogisticRegression(C, D)
    lr.train(X_train, Y_train)
    acc = lr.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')
