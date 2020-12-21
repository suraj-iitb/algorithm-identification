import numpy as np
import argparse
import sys
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

        #i = 0
        #maxi = -10000000000                           #######         #Change it#########

        E = self.weights.dot(x)
        return np.argmax(E, axis=0)
        #print("E=",E)





        # for j in range(self.weights.shape[0]):

        #     #print(self.weights[j,:].shape)
        #     #print(x.shape)

        #     value = self.weights[j,:].dot(x)

        #     if maxi < value:
        #         maxi = value
        #         i = j

        # return i        


        ### END TODO

    def train(self, X, Y, max_iter=2):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights
                #print(i)

                G = X[i,:]

                Z = self.pred(G)
                #print(Z)

                if Z!=Y[i]:
                    self.weights[Z,:] = self.weights[Z,:] - G
                    self.weights[Y[i],:] = self.weights[Y[i],:] + G


                ### END TODO

    def eval(self, X, Y):
        n_samples = X.shape[0]
        correct = 0
        for i in range(X.shape[0]):
            #print(correct)
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

    #print("check1")

    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    #print("check2")

    perceptron.train(X_train, Y_train)
    #print("check3")
    acc = perceptron.eval(X_test, Y_test)
    #print("check4")
    print(f'Test Accuracy: {acc}')





    # plt.figure()

    # l1 = []


    # for num_train_samples in [10,100,1000,10000,50000,80000]:
    #     X_train, Y_train, X_test, Y_test = get_data('D1',num_train_samples)
    #     C = max(np.max(Y_train), np.max(Y_test))+1
    #     D = X_train.shape[1]
    #     perceptron = Perceptron(C, D)
    #     perceptron.train(X_train, Y_train)
    #     acc = perceptron.eval(X_test, Y_test)
    #     l1.append(1-acc)
        
        

    # plt.plot(l1)

    # #plt.legend(['Train MSE', 'Test MSE'])
    # plt.xticks(list(range(6)),[10,100,1000,10000,50000,80000])
    # plt.xlabel('number of training samples')
    # plt.ylabel('Test Error')
    # plt.show()



