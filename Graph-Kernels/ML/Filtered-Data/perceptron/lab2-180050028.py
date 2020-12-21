import numpy as np
import argparse
import matplotlib.pyplot as plt


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
        x.reshape((x.shape[0],1))
        scores= np.dot(self.weights,x)
        scores = np.transpose(scores)
       # print(scores.shape)
        maximums = np.where(scores == np.amax(scores))[0]
        return  np.random.choice(maximums,1)[0]
        ### END TODO

    def train(self, X, Y, max_iter=2):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights
                predicted = self.pred(np.transpose(X[i]))
                if(predicted!=Y[i]):
                    self.weights[Y[i]] = self.weights[Y[i]] + X[i]
                    self.weights[predicted] = self.weights[predicted] - X[i]
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

    X_train, Y_train, X_test, Y_test = get_data('D1',num_train_samples)

    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    perceptron.train(X_train, Y_train)
    acc = perceptron.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')

    errors_data = []
    for num_train_samples in [10, 100, 1000, 10000, 50000, 80000]:
        X_train, Y_train, X_test, Y_test = get_data('D1',num_train_samples)

        C = max(np.max(Y_train), np.max(Y_test))+1
        D = X_train.shape[1]

        perceptron = Perceptron(C, D)

        perceptron.train(X_train, Y_train)
        acc = perceptron.eval(X_test, Y_test)    
        error = 1-acc
        errors_data.append(error)

    plt.figure(figsize=(12,12))
    sample_data = [10, 100, 1000, 10000, 50000, 80000]
    plt.plot(sample_data, errors_data)
    plt.xlabel('samples')
    plt.ylabel('test_error')
    plt.figtext(0.5, 0.01, "q2", wrap=True, horizontalalignment='center', fontsize=6)
    plt.show()
