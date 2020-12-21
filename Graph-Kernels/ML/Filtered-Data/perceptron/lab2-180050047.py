import numpy as np
import argparse

def get_data(dataset,num_train_samples=-1):
    datasets = ['D1', 'D2']
    assert dataset in datasets, "Dataset {dataset} not supported. Supported datasets {datasets}"
    X_train = np.loadtxt(f'data/{dataset}/training_data')
    Y_train = np.loadtxt(f'data/{dataset}/training_labels', dtype=int)
    X_test = np.loadtxt(f'data/{dataset}/test_data')
    Y_test = np.loadtxt(f'data/{dataset}/test_labels', dtype=int)

    return X_train[:num_train_samples,:], Y_train[:num_train_samples], X_test, Y_test

class Perceptron():
    def __init__(self, C, D):
        '''
        C - number of classes
        D - number of features
        '''
        self.C = C
        self.weights = np.zeros((C, D))
        
    def pred(self, x):
        '''
        x - numpy array of shape (D,)
        '''
        ### TODO: Return predicted class for x
        vals = np.matmul(self.weights,x.transpose())
        classified = np.argmax(vals)
        return classified
        ### END TODO

    def train(self, X, Y, max_iter=15):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update self.weights
                # print(i)
                vals = np.matmul(self.weights,X[i,:].transpose())
                # print(vals)
                classified = np.argmax(vals)
                # print(classified)
                if classified == Y[i]:
                    # print("asdf")
                    pass
                else:
                    # print("fads")
                    upt = self.weights[classified,:]
                    real = self.weights[Y[i],:]
                    upt = upt - X[i,:]
                    real = real + X[i,:]
                    self.weights[classified,:] = upt
                    self.weights[Y[i],:] = real
                ### END TODO
                # print("fd")

    def eval(self, X, Y):
        n_samples = X.shape[0]
        correct = 0
        for i in range(X.shape[0]):
            if self.pred(X[i]) == Y[i]:
                correct += 1
        return correct/n_samples

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Problem 4')
    parser.add_argument('--num_samples', type=int, default=-1,
                    help='Number of samples to train on')
    args = parser.parse_args()
    
    num_train_samples = args.num_samples
    print(num_train_samples)
    X_train, Y_train, X_test, Y_test = get_data('D1',num_train_samples)

    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    perceptron.train(X_train, Y_train)
    acc = perceptron.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')
