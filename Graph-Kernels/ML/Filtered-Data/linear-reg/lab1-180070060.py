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
	h_x = X @W 
	diff_term = h_x - Y
	diff_term = diff_term ** 2
	mse = (1/(2*n_samples))*np.sum(diff_term)

	## END TODO

	return mse


def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.03, max_iter=4000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_samples, n_features = X_train.shape
	
	W = np.random.normal(0,1,(n_features,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - lr * (1/n_samples)* (X_train.T @(X_train @ W - Y_train))
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=500):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal
	n_samples, n_features = X_train.shape

	W = np.random.normal(0,1,(n_features,1))


	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - lr * ((1/n_samples)* (X_train.T @(X_train @ W - Y_train)) + 2*reg*W)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''Bas likh denge expected graph aa raha h
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO

	new_X = np.diag(r) @ X
	p1 = new_X.T @ new_X
	new_Y = np.diag(r) @ Y
	W = np.linalg.inv(p1) @ (new_X.T @ new_Y)  	
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



