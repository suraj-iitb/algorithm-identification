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
        
        scores =  self.weights.dot(x).tolist()
        
        return scores.index(max(scores))
        ### END TODO

    def train(self, X, Y, max_iter=20):
        for _ in range(max_iter):
            for i in range(X.shape[0]):
                ### TODO: Update weights
                phi = X[i]
                true_label = Y[i]
                if(self.pred(phi) == true_label):
                    continue
                false_label = self.pred(phi)
                #score for false and true label
                #score_false = self.weights[false_label].dot(phi)
                #score_true = self.weights[true_label].dot(phi)
                
                #if score same but returned due to tie
                #if(score_false == score_true):
                #    self.weights[false_label] = self.weights[false_label] - phi
                #    continue
                
                self.weights[false_label] = self.weights[false_label] - phi
                self.weights[true_label] = self.weights[true_label] + phi
                
                ### END TODO

    def eval(self, X, Y):
        n_samples = X.shape[0]
        correct = 0
        for i in range(X.shape[0]):
            if self.pred(X[i]) == Y[i]:
                correct += 1
        return correct/n_samples

# +
#A = np.zeros((5,5))
#B = np.zeros((5))
#A[0].dot(B)
# -



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



'''
sampl = [10, 100, 1000, 10000, 50000, 80000]
test_err = []
    
for i in sampl:
    X_train, Y_train, X_test, Y_test = get_data('D1',i)

    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]

    perceptron = Perceptron(C, D)

    perceptron.train(X_train, Y_train)
    acc = perceptron.eval(X_test, Y_test)
    test_err.append(1-acc)

import matplotlib.pyplot as plt
fig = plt.figure(figsize=(4,4))
plt.plot(sampl, test_err)
plt.xlabel('Num_samples')
plt.ylabel('Test Error')
fig.savefig('test_err_vs_#samples.pdf')
'''

# +
#test_err
# -

'''
marks = 0
accs = [[0.78, 0.70, 0.60], [0.97, 0.90, 0.80]]

for i, ds in enumerate(['D1', 'D2']):
    X_train, Y_train, X_test, Y_test = get_data(ds)
        
    C = max(np.max(Y_train), np.max(Y_test))+1
    D = X_train.shape[1]
        
    p = Perceptron(C, D)
        
    p.train(X_train, Y_train)
    acc = p.eval(X_test, Y_test)
    
    if acc>=accs[i][0]:
        marks += 1.5
    elif acc>=accs[i][1]:
        marks += 1
    elif acc>=accs[i][2]:
        marks += 0.5
    break
'''

# +
#acc
# -


