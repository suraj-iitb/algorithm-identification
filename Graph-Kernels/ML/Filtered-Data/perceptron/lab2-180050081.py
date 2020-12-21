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

        n_samples = x.shape[0]
        x = x.reshape(n_samples, 1)

        score = (self.weights @ x)
        score = score.reshape(1,self.C)

        max_score_class = np.argmax(score)
        return max_score_class

        ### END TODO

    def train(self, X, Y, max_iter=2):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights

                predicted_y = self.pred(X[i])
                if predicted_y != Y[i]:
                    self.weights[Y[i]] += X[i]
                    self.weights[predicted_y] -= X[i]

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


    # # 3.2
    # arguments_list = [10, 100, 1000, 10000, 50000, 80000]
    # one_minus_acc_list = []
    # for num_arg in arguments_list:        
    #     X_train, Y_train, X_test, Y_test = get_data('D1',num_arg)

    #     C = max(np.max(Y_train), np.max(Y_test))+1
    #     D = X_train.shape[1]

    #     perceptron = Perceptron(C, D)

    #     perceptron.train(X_train, Y_train)
    #     acc = perceptron.eval(X_test, Y_test)

    #     one_minus_acc_list.append(1-acc)

    # plt.figure(1, figsize=(4,4))
    # plt.plot(arguments_list, one_minus_acc_list, marker='o')
    # plt.xscale('log')
    # plt.xlabel('Number of Training Samples')
    # plt.ylabel('Test Error(1-accuracy)')
    # plt.show()