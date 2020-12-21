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
	N = X.shape[0]
	mse = (1/(2*N))*np.sum(np.square(np.matmul(X,W)-Y))
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.068, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	N = X_train.shape[0]
	D = X_train.shape[1]
	W = np.random.normal(size=(D,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		#print(train_mse)
		## TODO: Update w and b using a single step of gradient descent
		W_old = W
		W = W_old - lr*(1/N)*(np.matmul(np.transpose(X_train),(np.matmul(X_train,W_old)-Y_train)))
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	N = X_train.shape[0]
	D = X_train.shape[1]
	W = np.random.normal(size=(D,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W) 
		test_mse = mse(X_test,Y_test,W) 
		#print(test_mse) 
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		
		## TODO: Update w and b using a single step of gradient descent
		W_old = W
		W = W_old - lr*((1/N)*np.matmul(np.transpose(X_train),(np.matmul(X_train,W_old)-Y_train)) + 2*reg*W_old)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO	
	N = X.shape[0]
	R = np.square(np.diag(r))
	XT = np.transpose(X)
	W = np.matmul(np.linalg.inv(np.matmul(XT,np.matmul(R,X))),np.matmul(XT,np.matmul(R,Y)))
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	#W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	#W1 = weighted_regression(X_train,Y_train,np.ones((X_train.shape[0],)))
	#print(W-W1)
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

