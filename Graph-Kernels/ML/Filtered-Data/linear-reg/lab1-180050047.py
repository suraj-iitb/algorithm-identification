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
	temp = (np.matmul(X,W) - Y)
	mse = (1/(2*Y.shape[0])) * (np.matmul(temp.transpose(),temp))
	mse = mse[0,0]
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0,0.1,[X_train.shape[1],1])
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		test_mse = mse(X_test,Y_test,W)
		train_mse = mse(X_train,Y_train,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		error = np.matmul(X_train,W) - Y_train
		newX = np.matmul(error.transpose(),X_train)
		W = W - (lr/X_train.shape[0])*(newX.transpose())
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=1000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0,0.1,[(X_train.shape[1]),1])
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		test_mse = mse(X_test,Y_test,W)
		train_mse = mse(X_train,Y_train,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp = np.matmul((np.matmul(X_train,W) - Y_train).transpose(),X_train).transpose()
		W = W - (lr/(X_train.shape[0]))*(temp)- lr*(2*reg*W)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	diagonal = np.diag(r)
	R = np.matmul(diagonal,diagonal)
	W = np.matmul(np.linalg.inv(np.matmul(np.matmul(X.transpose(),R),X)), np.matmul(np.matmul(X.transpose(),R),Y))
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	print(train_mses)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

