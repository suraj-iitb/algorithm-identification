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
	n = np.shape(X)[0]
	Y_est = Y-np.dot(X,W)
	mse = np.mean(Y_est**2)/2
	
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.04, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_train = np.shape(X_train)[0]
	n_test = np.shape(X_test)[0] 
	n_features = np.shape(X_train)[1]
	W = np.random.normal(0.0,1.0,n_features).reshape(n_features,1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		partial_derivative_w = -np.dot(np.transpose(X_train),Y_train-(np.dot(X_train,W)))/(n_train)
		W = W - lr*partial_derivative_w
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_train = np.shape(X_train)[0]
	n_test = np.shape(X_test)[0] 
	n_features = np.shape(X_train)[1]
	W = np.random.normal(0.0,1.0,n_features).reshape(n_features,1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		partial_derivative_w = (-np.dot(np.transpose(X_train),Y_train-(np.dot(X_train,W)))/(n_train))+(reg*2*W)
		W = W - lr*partial_derivative_w
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	n = np.shape(X)[0]
	n_features = np.shape(X)[1]
	diag_r = np.zeros((n,n))
	for i in range(n):
		diag_r[i][i]=r[i]
	newY = np.matmul(diag_r,Y)
	newX = np.matmul(diag_r,X)
	phi_tphiinv = np.linalg.inv(np.matmul(np.transpose(newX),newX))
	W = np.matmul(phi_tphiinv,np.matmul(np.transpose(newX),newY))
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	#print(X[0])
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

