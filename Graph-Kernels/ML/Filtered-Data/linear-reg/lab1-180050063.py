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
	n_samples  = X.shape[0]
	temp = X.dot(W)
	temp = temp-Y
	temp = temp**2
	mse = sum(temp)/(2*n_samples)


	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.2, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	(n_train,n_features) = X_train.shape
	W = np.random.normal(0,1,(n_features,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp = X_train.T
		temp = temp.dot(X_train)
		temp = temp.dot(W)
		temp1 = X_train.T
		temp1 = temp1.dot(Y_train)
		temp = temp - temp1
		temp = temp/(n_train/lr)
		W = W - lr*temp

		## END TODO
	#print(test_mses[-1])
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.075, max_iter=3000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []
	## TODO: Initialize W using using random normal 
	(n_train,n_features) = X_train.shape
	reg = 2*reg*n_train
	W = np.random.normal(0,1,(n_features,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp = X_train.T
		temp = temp.dot(X_train)
		temp = temp.dot(W)
		temp1 = X_train.T
		temp1 = temp1.dot(Y_train)
		temp = temp - temp1
		temp = temp + reg*W
		temp = temp/(n_train/lr)
		W = W - lr*temp
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
	U = R.dot(X)
	temp = (U.T).dot(U)
	temp = np.linalg.inv(temp)
	W = temp.dot((U.T).dot(R.dot(Y)))
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

