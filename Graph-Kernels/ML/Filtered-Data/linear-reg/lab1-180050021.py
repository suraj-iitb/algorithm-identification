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

	## TODO\
	
	D = Y-np.matmul(X,W)
	mse = np.mean(D**2)/2
	
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=4000):
	
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0.0,1.0,[np.shape(X_train)[1],1])
	#
	# # END TODO
	#W = np.random.rand(np.shape(X_train)[1],1)

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Dw = -(1/np.shape(X_train)[0])*np.matmul(np.transpose(X_train),(Y_train-np.matmul(X_train,W)))
		W = W - lr*Dw

		## END TODO

	return W, train_mses, test_mses


def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=50):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	W = np.random.normal(0.0,1.0,[np.shape(X_train)[1],1])
	## END TODO
	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Dw = -(1/np.shape(X_train)[0])*(np.matmul(np.transpose(X_train),(Y_train-np.matmul(X_train,W))))+2*reg*W
		W = W - lr*Dw
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''
	## TODO
	R = np.zeros([r.shape[0],r.shape[0]])
	for i in range(r.shape[0]):
		R[i,i] = r[i]*r[i]
	T1 = np.matmul(np.transpose(X),R,X)
	T2 = np.matmul(np.transpose(X),R,Y)
	W = np.matmul(np.linalg.inv(T1),T2)
	## END TODO
	print(W)
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)
	
	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()
	W, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()
