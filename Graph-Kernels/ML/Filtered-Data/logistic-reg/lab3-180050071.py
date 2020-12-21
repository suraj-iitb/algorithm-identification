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
        A=np.shape(X)
        N=A[0]
        C=self.C
        W=self.weights
        S=np.ones(C)
        # print(W)
        for i in range(N):
        	# print(X[i,:])
        	# print(W)
        	B=np.matmul(X[i,:],W)
        	# print("org B: ",B)
        	B=np.exp(B)
        	# print("after sum: ",B)
        	dnm=B.sum()
        	B=B/dnm
        	# print("after divide: ",B)
        	S=np.concatenate((S,B),axis=0)
        S=S.reshape((len(S)//C,C))
        # print("S: ",S)
        # print(np.shape(S))
        S=np.array(S[1:,:])
        return S
        # END TODO

    def predict(self, X):
        """
        :param X: numpy array of shape (N, D) corresponding to inpus data
        :return: numpy array of shape (N, 1) corresponding to predicted labels
        """
        # TODO: Return a (N, 1) numpy array of predictions.
        W=self.weights
        F=self.softmax(X)
        A=np.shape(X)
        N=A[0]
        Y=np.ones(N)
        C=self.C
        for i in range(N):
        	best_class=-1
        	best_val=-1
        	for j in range(C):
        		if(best_val<=F[i][j]):
        			best_class=j
        			best_val=F[i][j]
        	Y[i]=best_class
        return Y
        # END TODO

    def train(self, X, Y, lr=0.25, max_iter=100): # problem here
        Y = one_hot_encode(Y, np.unique(Y))
        for i in range(max_iter):
            # TODO: Update the weights using a single step of gradient descent. You are not allowed to use loops here.
            # Y=KxN
            # X=NxD
            # W=DxK
            # print(i)
            # print(i)
            W=self.weights
            Y=Y.transpose()

            A=np.shape(Y)
            K=A[0]
            N=A[1]
            # print(np.shape(Y))
            # print(np.shape(X))
            # print(np.shape(W))
            DT1= -1*np.matmul(Y,X)/N # DT1=KxD
            DT1=DT1.transpose() # DT1=DxK
            G=np.matmul(X,W) # G=NxK
            G=np.exp(G) # G=NxK
            # print("G: ",G)
            H=np.ones((K,K)) # H=KxK
            # print("H: ",H)
            I=np.matmul(G,H) # H=KxK
            # print("I: ",I)
            J=np.divide(G,I) # H=NxK
            # print("J: ",J)
            DT2=np.matmul(X.transpose(),J)/N # DT2=DxK
            EW=DT1+DT2
            W=W-lr*EW

            Y=Y.transpose()
            self.weights=W
            # END TODO

            # TODO: Stop the algorithm if the norm of the gradient falls below 1e-4
            val=np.multiply(EW,EW)
            val=np.sum(val)
            if(val<1e-8):
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
    # print(lr.weights)
    acc = lr.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')
