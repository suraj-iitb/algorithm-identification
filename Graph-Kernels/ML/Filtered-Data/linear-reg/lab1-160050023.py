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
	a = (X.dot(W) - Y)
	a = np.multiply(a,a)
	mse = a.sum()/(2.0*np.size(X,0))
	##print(mse)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.0005, max_iter=3000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0.0, 0.001, (X_train.shape[1], 1))
	#print(W)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		#print(train_mse, test_mse)

		## TODO: Update w and b using a single step of gradient descent
		a = (X_train.dot(W)-Y_train)
		b = np.transpose(X_train)
		c = b.dot(a)
		m = c/float(X_train.shape[0])
		W = W - lr*m

		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=4000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal `
	W = np.random.normal(0.0, 0.001, (X_train.shape[1], 1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train, Y_train, W)
		test_mse = mse(X_test, Y_test, W)
		## print(test_mse)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		a = (X_train.dot(W)-Y_train)
		b = np.transpose(X_train)
		c = b.dot(a) + reg*W
		m = c/float(X_train.shape[0])
		W = W - lr*m
		## END TODO
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO 
	#r.reshape(Y.shape[0], 1)
	lr = 0.01
	W = np.random.normal(0.0, 0.01, (X.shape[1], 1))
	for i in range(r.shape[0]):
		r[i] = float(r[i]) ** 2
	r = np.reshape(r,(Y.shape[0],1))
	#print(Y)
	#print(r)
	#print(W)
	for i in range(4000):
		#xprint(i, mse(X,Y,W))
		a = np.multiply(r, (X.dot(W)-Y))
		b = np.transpose(X)
		c = b.dot(a)
		m = c/float(Y.shape[0])
		W = W - lr*m
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

