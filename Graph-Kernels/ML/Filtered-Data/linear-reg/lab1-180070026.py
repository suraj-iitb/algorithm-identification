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
	## END TODO
	return np.mean( (Y.flatten() - np.dot(X, W.flatten()) ) ** 2 ) / 2

def grad(X, Y, W):
    return (np.dot(np.dot(X.T, X), W) - np.dot(X.T, Y.flatten())) / X.shape[0]

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=2000):
	train_mses = []
	test_mses = []
	## TODO: Initialize W using using random normal 
	W = np.random.randn(X_train.shape[1])
	## END TODO

	for _ in range(max_iter):
		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - lr * grad(X_train, Y_train, W)
		## END TODO
	# print(train_mses[-1], test_mses[-1])
	return W[:, np.newaxis], train_mses, test_mses

def reg_mse(X, Y, W, reg):
	W = W.flatten()
	return (np.mean((Y.flatten() - np.dot(X, W)) ** 2) / (2 * X.shape[0]))  + reg * np.dot(W, W)

def grad1(X, Y, W, reg):
	return np.dot((np.dot(X.T, X) / X.shape[0]) + 2 * reg * np.eye(W.shape[0]), W) - (np.dot(X.T, Y.flatten()) / X.shape[0])

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []
	## TODO: Initialize W using using random normal 
	W = np.random.randn(X_train.shape[1],)
	## END TODO

	for _ in range(max_iter):
		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO
		train_mses.append(train_mse)
		test_mses.append(test_mse)
		## TODO: Update w and b using a single step of gradient descent
		W_new = W - lr * grad1(X_train, Y_train, W, reg)
		if(mse(X_train, Y_train, W_new) >= train_mse): break
		W = W_new
		## END TODO

	return W[:, np.newaxis], train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''
	## TODO
	R = np.diag(r)
	X = np.dot(R, X)
	Y = np.dot(R, Y)
	W = np.dot( np.linalg.inv(np.dot(X.T, X)), np.dot(X.T, Y) )
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	print(train_mses[-1], test_mses[-1])
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

