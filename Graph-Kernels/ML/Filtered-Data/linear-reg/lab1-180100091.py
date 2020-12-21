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
	# print(type(X[0][0]),type(W[0]))
	
	loss = np.matmul(X,W) - Y
	n = X.shape[0]
	loss_trans = loss.transpose()
	mse = np.dot(loss_trans, loss)/(2*n)
	mse = mse.item()
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.04, max_iter=2000):
	train_mses = []
	test_mses = []
	d = X_train.shape[1]
	## TODO: Initialize W using using random normal 
	W = np.random.normal(0,1,(d,1))
	## END TODO
	n = X_train.shape[0]
	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse  = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - lr*np.dot(np.transpose(X_train), np.dot(X_train,W)-Y_train)/n
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.04, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	d = X_train.shape[1]
	## TODO: Initialize W using using random normal 
	w = np.random.normal(0,1,(d,1))
	## END TODO'
	n = X_train.shape[0]

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse  = mse(X_train,Y_train,w) 
		test_mse = mse(X_test,Y_test,w)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		w = w - lr*np.dot(np.transpose(X_train), np.matmul(X_train,w)-Y_train)/n - 2*reg*lr*w

		## END TODO

	return w, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	W = np.matmul(np.matmul(np.matmul(np.linalg.inv(np.matmul(np.matmul(np.matmul(X.transpose(),r.transpose()),r),x)),(X.transpose()),r.transpose()),r),Y)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	#W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	n = X_train.shape[0]
	#w = weighted_regression(X_train,Y_train,np.ones(n))
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

