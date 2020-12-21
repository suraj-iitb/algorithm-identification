import numpy as np
import matplotlib.pyplot as plt
from utils import load_data2, split_data, preprocess, normalize

np.random.seed(337)

def mse(X, Y, W):
    '''
    Compute mean squared error between predictions and true y values
    Args:
	X - numpy array of shape (n_samples, n_features)
	Y - numpy array of shape (n_samples, 1)
	W - numpy array of shape (n_features, 1)
	'''
    ## TODO
    n = float(X.shape[0])
    mse = np.sum((X.dot(W) - Y)**2)/(2*n)
    ## END TODO
    
    return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.009, max_iter=5000):
    train_mses = []
    test_mses = []
    
    ## TODO
    # Initialize W using using random normal 
    np.random.seed(1)
    n = float(X_train.shape[0])
    W = np.random.randn(X_train.shape[1], 1)#shape is parameter
    ## END TODO
    
    for i in range(max_iter):
        ## TODO: Compute train and test MSE
        
        train_mse = mse(X_train, Y_train, W) 
        test_mse = mse(X_test, Y_test, W)
        ## END TODO
        
        train_mses.append(train_mse)
        test_mses.append(test_mse)
        
        ## TODO: Update w and b using a single step of gradient descent
        loss = X_train.dot(W) - Y_train
        grad = X_train.T.dot(loss)/n
        W = W - lr*grad
        ## END TODO
        
    return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.005, max_iter=5000):
    train_mses = []
    test_mses = []
    
    ## TODO
    # Initialize W using using random normal
    np.random.seed(2)
    n = float(X_train.shape[0])
    W = np.random.randn(X_train.shape[1], 1)#shape is parameter
    ## END TODO
    
    for i in range(max_iter):
        
        ## TODO: Compute train and test MSE
        train_mse = mse(X_train, Y_train, W) #+ reg*np.sum(W**2)
        #train_mse = train_mse + reg*np.sum(W**2)
        
        test_mse = mse(X_test, Y_test, W) #+ reg*np.sum(W**2)
        #test_mse = test_mse + reg*np.sum(W**2)
        ## END TODO
        
        train_mses.append(train_mse)
        test_mses.append(test_mse)
        
        ## TODO: Update w and b using a single step of gradient descent
        #n = X_train.shape[0]
        loss = X_train.dot(W) - Y_train
        grad = (1/n) * (X_train.T.dot(loss)) + 2*reg*W
        W = W - lr*grad
        
        ## END TODO

    return W, train_mses, test_mses

def weighted_regression(X, Y, r):
    '''
    Fill up this function for problem 3.
    Use closed form expression.
    r_train is a (n,) array, where n is number of training samples
    '''
    ## TODO
    R = np.diag(r)
    X_ = R.dot(X)
    #X_ = X
    #Y_ = Y
    Y_ = R.dot(Y)
    W = np.linalg.inv(X_.T.dot(X_)).dot(X_.T).dot(Y_)
    
    ## END TODO
    return W


r = np.array([1,2,3])
np.diag(r)





if __name__ == '__main__':
    # Load and split data
    X, Y = load_data2('data2.csv')
    X, Y = preprocess(X, Y)
    X_train, Y_train, X_test, Y_test = split_data(X, Y)
    
    
    #W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
    W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
    
    # Plots
    #fig=plt.figure(figsize=(4,4))
    plt.figure(figsize=(4,4))
    plt.plot(train_mses)
    plt.plot(test_mses)
    plt.legend(['Train MSE', 'Test MSE'])
    plt.xlabel('Iteration')
    plt.ylabel('MSE')
    #fig.savefig('q2ridge.pdf')
    plt.show()


# +
#np.random.randn(2, 1)

# +
#1168/1460
#test_mses[-1]

# +
#train_mses[-10:]

#assert (W_ridge@W_ridge.T)[0][0] < 1e-7
#assert np.linalg.norm(W_ridge - W_act) < 0.5
# +
#test_mses
#(W_ridge@W_ridge.T)[0][0]

# +
#X, Y = load_data2('data2.csv')
#np.random.randn(X.shape[1], 1)


# +

#reg = 10
#W_act = np.linalg.inv(X_train.T @ X_train + 2 * reg * X_train.shape[0] * np.eye(X_train.shape[1])) @ X_train.T @ Y_train
#np.linalg.norm(W_ridge - W_act)
# -

'''
assert train_mses[-1] < 0.3
assert test_mses[-1] < 0.35
assert (W_ridge@W_ridge.T)[0][0] < 1e-7
assert np.linalg.norm(W_ridge - W_act) < 0.5
'''



# +
#W_act = np.linalg.inv(X_train.T @ X_train + 2 * reg * X_train.shape[0] * np.eye(X_train.shape[1])) @ X_train.T @ Y_train
#(W_act@W_act.T)[0][0]

# +
#mse(X_train, Y_train, W_act)
# -

'''
for i in range(len(train_mses)-1):
    print(train_mses[i] >= train_mses[i+1])
    if(train_mses[i] < train_mses[i+1]):
        break
i
'''


