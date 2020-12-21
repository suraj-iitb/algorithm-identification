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
	n_samples = np.shape(X)[0]
	n_features = np.shape(X)[1]
	mse = 0.0
	for i in range(n_samples):
		t = 0.0
		for j in range(n_features):
			t = t + W[j]*X[i][j]
		mse = mse + (t - Y[i])**2
	mse = mse /(2*n_samples)
	# mse = np.dot(X,W) - Y
	# mse = 1/(2*n_samples)

	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.065, max_iter=700):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_samples = np.shape(X_train)[0]
	n_features = np.shape(X_train)[1]
	W = np.random.normal(0,1,n_features)
	#print(n_samples,n_features)
	#print(np.shape(X_train),np.shape(Y_train))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test, W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp = 0
		XW = np.dot(X_train,W)
		Z = np.zeros(n_samples)
		for j in range(n_samples):
			Z[j]=XW[j]-Y_train[j]

		#print(np.shape(Z))
		Z1 = np.dot(np.transpose(X_train),Z)
		#print(np.shape(Z1))
		W = W - (lr/n_samples)*(Z1)
		print(i, train_mse)
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.065, max_iter=700):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_samples = np.shape(X_train)[0]
	n_features = np.shape(X_train)[1]
	#print(n_samples,n_features)
	W = np.random.normal(0,1,n_features)
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W) + reg*np.dot(W,W)
		test_mse = mse(X_test,Y_test,W) + reg*np.dot(W,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		XW = np.dot(X_train,W)
		Z = np.zeros(n_samples)
		for j in range(n_samples):
			Z[j] = XW[j]-Y_train[j]
		Z1 = np.dot(np.transpose(X_train),Z)
		W = W - lr*(Z1/n_samples + 2*reg*W)
		#print(i)
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	n = np.shape(r)[0]
	R = np.zeros((n,n))
	for i in range(n):
		R[i][i] = r[i]
	W1 = np.linalg.inv(X.T @ R @ X)
	W2 = X.T @ R @ Y 
	W = W1 @ W2
	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	#W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)

	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()

