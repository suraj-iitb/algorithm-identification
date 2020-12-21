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
	n_samples = X.shape[0]
	mse = (np.linalg.norm(X*W - Y)**2) / (2*n_samples)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.00001, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.matrix(np.random.rand(X_train.shape[1], 1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - lr * (X_train.T * (X_train*W - Y_train))
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.00001, max_iter=4000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.matrix(np.random.rand(X_train.shape[1], 1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = (np.linalg.norm(np.matrix(X_train)*np.matrix(W) - np.matrix(Y_train))**2) / (2*X_train.shape[0])
		train_mse += reg * np.linalg.norm(np.matrix(W))**2 / (2*X_train.shape[0])
		test_mse = (np.linalg.norm(np.matrix(X_test)*np.matrix(W) - np.matrix(Y_test))**2) / (2*X_test.shape[0])
		test_mse += reg * np.linalg.norm(np.matrix(W))**2 / (2*X_train.shape[0])
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		# one = 2 * (np.transpose(np.matrix(X_train))) * (np.matrix(X_train) * W - np.matrix(Y_train)) 
		# two = 2 * W * reg
		# grad = one + two
		grad = (X_train.T * (X_train*W - Y_train)) + (W * reg)
		W = W - lr * grad
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	lr = 0.00001
	max_iter = 2000
	n_samples = X.shape[0]
	n_features = X.shape[1]
	R = np.matrix(r)
	W = np.matrix(np.random.rand(n_features, 1))
	for i in range(max_iter):
		grad = (X.T * R * X * W) - (X.T * R * Y)
		W = W - lr * grad
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
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

