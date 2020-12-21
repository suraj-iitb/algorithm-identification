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
        #print(x.shape)
        scores=np.matmul(self.weights,x)
        ans=np.where(scores==np.amax(scores))
        #print(ans)
        
        return ans[0][0]
        
        ### END TODO

    def train(self, X, Y, max_iter=2):
        #print(self.weights.shape)
        for _ in range(max_iter):
            #print(_)
            for i in range(X.shape[0]):
                ### TODO: Update weights
                y0=Y[i]
                y1=self.pred(X[i])
                #print(y0,y1,sep=' ')
                if y0!=y1:
                    self.weights[y0]+=X[i]
                    self.weights[y1]-=X[i]
                    
                
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
    #print(f'Num Samples: {num_train_samples}')
    #print(f'Test Error: {1-acc}')
    
    
    ##Plot 3a
    '''
    import matplotlib.pyplot as plt
    ll=[10,100,1000,10000,50000,80000]
    errs=[]
    for i in ll:
        X_train, Y_train, X_test, Y_test = get_data('D1',i)

        C = max(np.max(Y_train), np.max(Y_test))+1
        D = X_train.shape[1]

        perceptron = Perceptron(C, D)

        perceptron.train(X_train, Y_train)
        acc = perceptron.eval(X_test, Y_test)
        errs.append(1-acc)
    plt.xscale('log')
    plt.plot([10,100,1000,10000,50000,80000],errs,label='Test Set Error')
    plt.xlabel('Number of Training Samples')
    plt.ylabel('Test Set Error')
    plt.legend()
    plt.show()
    '''
    
    
