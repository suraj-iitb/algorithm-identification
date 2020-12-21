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
        w = self.weights
        # x.reshape((x.shape[0],1))
        w1 = np.dot(w,x)
        max = w1[0]
        var=0
        for i in range(len(w1)):
            if w1[i]>max:
                max = w1[i]
                var = i
        return var
        ### END TODO

    def train(self, X, Y, max_iter=2):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights
                yhat = self.pred(X[i])
                if yhat!=Y[i]:
                    self.weights[yhat] -= X[i]
                    self.weights[Y[i]] += X[i]
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
    # print(X_train.shape)
    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    perceptron.train(X_train, Y_train)
    acc = perceptron.eval(X_test, Y_test)
    print(f'Test Accuracy: {acc}')

    test_acc = [1-0.2633,1-0.52175,1-0.78025,1-0.77875,1-0.7742,1-0.79905]
    num = [10,100,1000,10000,50000,80000]
    plt.figure(figsize=(4,4))
    plt.plot(num,test_acc,marker='x')
    # plt.legend(['Train MSE', 'Test MSE'])
    plt.xlabel('Number of Samples')
    plt.ylabel('Accuracy of Perceptron')
    plt.show()