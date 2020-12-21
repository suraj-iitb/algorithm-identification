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
        self.weights = 0.1*np.random.randn(D, C)

    def softmax(self, X):
        """
        :param X: (N, D) array
        :return: softmax for given X and current weights
        """
        # TODO: Compute Softmax
        W = self.weights
        unnorm_logp = X @ W
        #print(np.max(np.abs(unnorm_logp)))
        unnorm_p = np.exp(unnorm_logp)
        sum_unnrom_p = np.sum(unnorm_p,axis=1,keepdims=True)
        norm_p = unnorm_p/sum_unnrom_p
        return norm_p

    def predict(self, X):
        """
        :param X: numpy array of shape (N, D) corresponding to inpus data
        :return: numpy array of shape (N, 1) corresponding to predicted labels
        """
        # TODO: Return a (N, 1) numpy array of predictions.
        pred = np.argmax(X @ self.weights,axis=1)
        return pred

        # END TODO

    def train(self, X, Y, lr=0.1, max_iter=1000):
        Y = one_hot_encode(Y, np.unique(Y))
        N = Y.shape[0]
        assert Y.shape[1]==self.C
        for i in range(max_iter):
            # TODO: Update the weights using a single step of gradient descent. You are not allowed to use loops here.
            
            # END TODO
            sfmax = self.softmax(X)
            grad = - X.T @ (Y - sfmax) / N
            self.weights -= lr*grad
            # TODO: Stop the algorithm if the norm of the gradient falls below 1e-4
            if np.linalg.norm(grad) < 1e-4:
                print("Converge")
                break
            # End TODO
            pass
        return 

    def eval(self, X, Y):
        """
        X - numpy array of shape (N, D) corresponding to inpus data
        Y - numpy array of shape (N, 1) corresponding to true labels
        """
        preds = self.predict(X)
        # print(preds)
        # print(Y)
        accuracy = ((preds == Y).sum()) / len(preds)
        return accuracy


if __name__ == '__main__':
    np.random.seed(335)

    X_train, Y_train, X_test, Y_test = get_data("D1")
    Y_train_true = np.array(Y_train)
    C = max(np.max(Y_train), np.max(Y_test)) + 1
    D = X_train.shape[1]

    lr = LogisticRegression(C, D)
    lr.train(X_train, Y_train)
    acc = lr.eval(X_train, Y_train_true)
    print(f'Train Accuracy: {acc}')    
    acc = lr.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')
