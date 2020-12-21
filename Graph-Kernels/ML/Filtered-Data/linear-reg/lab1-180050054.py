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
	#X = X.astype(float)
	# print(type(X[0][0]))
	# print(type(W[0][0]))
	Y_pred = X.dot(W)

	e = Y - Y_pred
	se = e.T.dot(e)
	mse = se[0][0]/(2*X.shape[0])
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.00001, max_iter=2000):
	train_mses = []
	test_mses = []
	n_features = X_train.shape[1]
	## TODO: Initialize W using using random normal 
	W = np.random.normal(0,0.2,[n_features,1])
	
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		## END TODO
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - 2*lr*(X_train.T.dot((X_train.dot(W) - Y_train)))
    	#b = b - lr*np.mean(w*X_train+b-Y_train)
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=3000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_features = X_train.shape[1]

	W = np.random.normal(0,0.005,[n_features,1])
	
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)# + reg*np.linalg.norm(W, ord = 'fro')*np.linalg.norm(W, ord = 'fro')
		test_mse = mse(X_test,Y_test,W)# + reg*np.linalg.norm(W, ord = 'fro')*np.linalg.norm(W, ord = 'fro')
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		W = W - (lr/X_train.shape[0])*(X_train.T.dot((X_train.dot(W) - Y_train))) -  2*lr*reg*W
		
		## END TODO

	return W, train_mses, test_mses


def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	Xr = np.multiply(X, r[:, np.newaxis])
	Yr = np.multiply(Y, r[:, np.newaxis])
	

	
	return np.linalg.inv(Xr.T @ Xr) @ (Xr.T @ Yr)

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	#print(X[0])
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	#W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

