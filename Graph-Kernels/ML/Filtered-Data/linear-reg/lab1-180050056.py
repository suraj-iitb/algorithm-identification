import numpy as np
import matplotlib.pyplot as plt
from numpy import random
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
	n_f=len(X[0])
	n_s=len(X)
	m1=np.subtract(np.dot(X,W),Y)
	m=sum(np.square(m1))
	mse = m/n_s
	mse=mse/2
	## END TODO
	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.03, max_iter=2000):
	train_mses = []
	test_mses = []
	l=len(X_train[0])
	m=len(X_train)
	## TODO: Initialize W using using random normal 
	W = random.normal(loc=0, scale=1, size=(l,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)
		test_mse=mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		A=X_train.transpose()
		W=np.subtract(W,(lr/m)*(np.dot(A,np.subtract(np.dot(X_train,W),Y_train))))
		## END TODO
	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.0001, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []
	l=len(X_train[0])
	m=len(X_train)
	## TODO: Initialize W using using random normal 
	W = random.normal(loc=0,scale=0.00005,size=(l,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		K=reg*sum(np.square(W))
		K=K/2
		K=K/m
		train_mse=mse(X_train,Y_train,W)+K
		test_mse=mse(X_test,Y_test,W)+K
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		A=X_train.transpose()
		W=np.subtract(W*(1-(2*lr*reg)),(lr/m)*(np.dot(A,np.subtract(np.dot(X_train,W),Y_train))))
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''
	m=len(X)
	## TODO
	C= np.zeros([m,m], dtype = float)
	for i in range(m):
		C[i,i]=r[i]*r[i]
	A=X.transpose()
	B=np.dot(np.dot(A,C),X)
	D= np.linalg.pinv(B)
	W=D@A@C@Y
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

