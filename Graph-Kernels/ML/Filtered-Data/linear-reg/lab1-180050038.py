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
	mse=np.dot((np.dot(X,W)-Y).T,(np.dot(X,W)-Y))
	# mse=np.sum(np.square(np.dot(X,W)-Y))
	mse/=(2*X.shape[0])
	# print(mse)
	## END TODO

	return mse[0][0]

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.00003, max_iter=15000):
	 # lr=0.000030, max_iter=15000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=np.random.normal(0,0.1,X_test.shape[1])
	W.shape=(W.shape[0],1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)
		## TODO: Update w and b using a single step of gradient descent
		W=W-lr*(np.dot((np.dot(X_train,W)-Y_train).T,X_train).T)/X_train.shape[0]
		# W=W-(lr*np.dot(X_train.T,(np.dot(X_train,W)-Y_train))/X_train.shape[0])
		## END TODO
	# print(train_mses[-1])
	# print(test_mses[-1])
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.00003, max_iter=11000):
	'''
	reg - regularization parameter (lambda in Q2.1 c);lr=0.002, max_iter=73950):
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W=np.random.normal(0,0.01,X_train.shape[1])
	# print(W.shape)
	W.shape=(W.shape[0],1)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)+(reg*np.square(np.linalg.norm(W))/(2*X_train.shape[0]))
		test_mse=mse(X_test,Y_test,W)+(reg*np.square(np.linalg.norm(W))/(2*X_test.shape[0]))
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		# W=W-lr*((np.dot((np.dot(X_train,W)-Y_train).T,X_train).T)+reg*W)/X_train.shape[0]
		W=W-(lr*(np.dot(X_train.T,(np.dot(X_train,W)-Y_train))+reg*W)/X_train.shape[0])
		## END TODO
	# print(W@W.T[0][0])
	# T1=np.dot(W,W.T)
	# print(T1[0][0])
	# print(train_mses[-1])
	# print(test_mses[-1])
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R=np.zeros((X.shape[0],X.shape[1]))
	np.fill_diagonal(R,r)
	RX=np.dot(R,X)
	T1=np.linalg.inv(np.dot(RX.T,RX))
	RY=np.dot(R,Y)
	W=np.dot(np.dot(T1,RX.T),RY)
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# print(test_mses[0])
	# W_weigh=weighted_regression(X_train,Y_train,)
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

