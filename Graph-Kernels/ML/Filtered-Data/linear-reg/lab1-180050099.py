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
	n_samples=X.shape[0]
	mse=(1/(2*n_samples))*np.sum(np.square(np.dot(X,W)-Y))
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.01, max_iter=10000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	[n_samples,n_features]=X_train.shape
	W=np.random.randn(n_features,1)
	# b=np.random.randn(n_samples,1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		
		W=W-((lr/n_samples)*(np.dot(np.transpose(X_train),np.dot(X_train,W)-Y_train)))
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=10000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	[n_samples,n_features]=X_train.shape
	W=np.random.randn(n_features,1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		# if(i==max_iter-1):
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		# else:
		# 	train_mse=mse(X_train,Y_train,W)+reg*np.square(np.linalg.norm(W))
		# 	test_mse=mse(X_test,Y_test,W)+reg*np.square(np.linalg.norm(W))
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W=W*(1-(2*lr*reg))-((lr/n_samples)*(np.dot(np.transpose(X_train),np.dot(X_train,W)-Y_train)))
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	W=np.dot(np.linalg.inv(np.dot(np.dot(np.transpose(X),np.square(np.diag(r))),X)),np.dot(np.dot(np.transpose(X),np.square(np.diag(r))),Y))
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# print(test_mses[-1])
	# print(train_mses[-1])
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

