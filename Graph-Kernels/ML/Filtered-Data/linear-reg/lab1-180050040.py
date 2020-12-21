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
	y_hat = np.matmul(X,W)
	m = np.sum((y_hat - Y)**2,axis=0)/Y.shape[0]
	mse = float(m/2)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test,  lr=0.06, max_iter=2500):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n,d = X_train.shape
	W = np.random.normal(0,1,(d,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		D_w = (-1)*np.matmul(X_train.T,Y_train - (np.matmul(X_train,W)))
		W = W-lr*(D_w/n)
		## END TODO

	# print(train_mses[-1])
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=600):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n,d = X_train.shape
	W = np.random.normal(0,1,(d,1))*0.001
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W) 
		test_mse = mse(X_test,Y_test,W) 
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		D_w = (1/n) * np.matmul(np.transpose(X_train),(np.matmul(X_train,W) - Y_train)) + 2*reg*W
		W = W - lr*D_w
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
	X = np.matmul(R,X)
	Y = np.matmul(R,Y)
	W = np.matmul(np.linalg.inv(np.matmul(X.T,X)),(np.matmul(X.T,Y)))
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

