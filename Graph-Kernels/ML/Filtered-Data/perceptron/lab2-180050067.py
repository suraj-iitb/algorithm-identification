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
        scores = np.matmul(self.weights, x)
        return np.argmax(scores)
        ### END TODO

    def train(self, X, Y, max_iter=3):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights
                y_pred, y_true = self.pred(X[i]), Y[i]
                if y_pred != y_true:
                    self.weights[y_pred] -= X[i]
                    self.weights[y_true] += X[i]
                ### END TODO

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

    X_train, Y_train, X_test, Y_test = get_data('D1', num_train_samples)

    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    perceptron.train(X_train, Y_train)
    acc = perceptron.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')

    # import matplotlib.pyplot as plt
    # import os
    # if not os.path.exists('plots'):
    #     os.makedirs('plots')
    # sample_set = [10, 100, 1000, 10000, 50000, 80000]
    # test_errors = []
    # for samples in sample_set:
    #     X_train, Y_train, X_test_waste, Y_test_waste = get_data('D1', samples)
    #     D = X_train.shape[1]
    #     perceptron = Perceptron(C, D)
    #     perceptron.train(X_train, Y_train, max_iter=2)
    #     acc = perceptron.eval(X_test, Y_test)
    #     test_errors.append(1.0 - acc)
    
    # plt.figure()
    # plt.plot(sample_set, test_errors, marker='o')
    # plt.xlabel('Number of Samples')
    # plt.ylabel('Test Error')
    # plt.xscale('log')
    # plt.savefig('plots/errors_vs_samples.png', bbox_inches='tight')
    