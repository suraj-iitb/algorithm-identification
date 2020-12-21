import numpy as np
import matplotlib.pyplot as plt
from utils import load_data2, split_data, preprocess, normalize

np.random.seed(337)

def mse(x, y, w):
    '''
    Compute mean squared error between predictions and true y values

    Args:
    X - numpy array of shape (n_samples, n_features)
    Y - numpy array of shape (n_samples, 1)
    W - numpy array of shape (n_features, 1)
    '''

    ## TODO
    n = np.size(y)
    mse = np.sum((np.dot(x,w)-y)**2)/(2*n)
    ## END TODO

    return mse

def ordinary_least_squares(x_train, y_train, x_test, y_test, lr=0.001, max_iter=2500):
    train_mses = []
    test_mses = []

    ## TODO: Initialize W using using random normal 
    w = []
    [m,n] = np.shape(x_train)
    for i in range(n):
        w.append(np.random.normal(0,0.1))
    w = np.array(w)
    w = w.reshape(n,1)
    ## END TODO

    for i in range(max_iter):

        ## TODO: Compute train and test MSE
        train_mse = mse(x_train,y_train,w)
        test_mse = mse(x_test,y_test,w)
        ## END TODO
        train_mses.append(train_mse)
        test_mses.append(test_mse)

        ## TODO: Update w and b using a single step of gradient descent
        mult = np.dot(x_train.T,np.dot(x_train,w)-y_train)
        w -= mult*(lr/m)
        ## END TODO
    
    return w, train_mses, test_mses

def ridge_regression(x_train, y_train, x_test, y_test, reg, lr=0.0001, max_iter=4000):
    '''
    reg - regularization parameter (lambda in Q2.1 c)
    '''
    train_mses = []
    test_mses = []

    ## TODO: Initialize W using using random normal 
    w = []
    [m,n] = x_train.shape
    for i in range(n):
        w.append(np.random.normal(0,0.01))
    w = np.array(w)
    w = w.reshape(n,1)
    ## END TODO

    for i in range(max_iter):

        ## TODO: Compute train and test MSE
        train_mse = mse(x_train,y_train,w)
        test_mse = mse(x_test,y_test,w)
        ## END TODO

        train_mses.append(train_mse)
        test_mses.append(test_mse)

        ## TODO: Update w and b using a single step of gradient descent
        w -= (np.dot(x_train.T,np.dot(x_train,w)-y_train))*(lr/m)+2*reg*w*lr
        ## END TODO
    return w, train_mses, test_mses

def weighted_regression(x, y, r):
    '''
    Fill up this function for problem 3.
    Use closed form expression.
    r_train is a (n,) array, where n is number of training samples
    '''

    ## TODO
    m = np.size(r)
    r = r.reshape(m,1)
    x = x*r
    y = y*r
    w = np.linalg.pinv(x.T@x)@x.T@y
    ## END TODO
    return w

if __name__ == '__main__':
    # Load and split data
    X, Y = load_data2('data2.csv')
    X, Y = preprocess(X, Y)
    X_train, Y_train, X_test, Y_test = split_data(X, Y)

    W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
    #W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

    # Plots
    plt.figure(figsize=(4,4))
    plt.plot(train_mses)
    plt.plot(test_mses)
    plt.legend(['Train MSE', 'Test MSE'])
    plt.xlabel('Iteration')
    plt.ylabel('MSE')
    plt.show()

