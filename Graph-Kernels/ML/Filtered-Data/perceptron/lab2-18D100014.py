import numpy as np
import argparse
import matplotlib.pyplot as plt

def get_data(dataset,num_train_samples=-1):
    # I had to make the necessary changes, I have commented the original code and made changes because
    # I had an older python version and it gave a compilation error with the original code

    #datasets = ['D1', 'D2']
    datasets = ["D1", "D2"]
    assert dataset in datasets, "Dataset {dataset} not supported. Supported datasets {datasets}"
    '''X_train = np.loadtxt(f'data/{dataset}/training_data')
    Y_train = np.loadtxt(f'data/{dataset}/training_labels', dtype=int)
    X_test = np.loadtxt(f'data/{dataset}/test_data')
    Y_test = np.loadtxt(f'data/{dataset}/test_labels', dtype=int)'''

    X_train = np.loadtxt("data/"+dataset+"/training_data")
    Y_train = np.loadtxt("data/"+dataset+"/training_labels", dtype=int)
    X_test = np.loadtxt("data/"+dataset+"/test_data")
    Y_test = np.loadtxt("data/"+dataset+"/test_labels", dtype=int)

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

        W=self.weights
        maxi=-1
        idx=-1
        C=np.matmul(W,x)
        D=len(C)
        for i in range(D):
            curr=C[i]
            if maxi < curr:
                maxi=curr
                idx=i

        return idx

        ### END TODO

    def train(self, X, Y, max_iter=2):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights

                #print(X[i].shape)
                Y_prime=self.pred(X[i])
                if Y_prime != Y[i]:
                    #print(self.weights[Y[i]].shape)
                    self.weights[Y[i]] = self.weights[Y[i]] + X[i]
                    self.weights[Y_prime] = self.weights[Y_prime] - X[i] 


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

    X_train, Y_train, X_test, Y_test = get_data("D1",num_train_samples)

    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    perceptron.train(X_train, Y_train)
    acc = perceptron.eval(X_test, Y_test)
    #print(f'Test Accuracy: {acc}')
    print("Test Accuracy: ",acc)

    # the code for 3.2 part 1

    num_samples=[10, 100, 1000, 10000, 50000, 80000]
    test_err=[]

    for i in num_samples:
        X_train, Y_train, X_test, Y_test = get_data("D1",i)

        C = max(np.max(Y_train), np.max(Y_test))+1
        D = X_train.shape[1]

        perceptron = Perceptron(C, D)

        perceptron.train(X_train, Y_train)
        acc = perceptron.eval(X_test, Y_test)
        #print(f'Test Accuracy: {acc}')
        #print("Test Accuracy: ",acc)
        test_err.append(1-acc)

    print(test_err)
    plt.figure(figsize=(4,4))
    plt.xscale("log")
    plt.plot(num_samples, test_err)
    plt.xlabel('Number of samples')
    plt.ylabel('Test Error')
    plt.show()
