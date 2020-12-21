import numpy as np
import matplotlib.pyplot as plt
from utils import load_data2, split_data, preprocess, normalize
from sklearn.linear_model import Ridge
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
	m = Y.shape[0]
	return np.sum((np.matmul(X,W)-Y)**2)/(2*m)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	m,n = X_train.shape
	W = np.random.randn(n,1)
	## END TODO

	for i in range(max_iter):
		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Y_pred = np.matmul(X_train,W)
		dw = np.matmul(np.transpose(X_train),(Y_pred-Y_train))/m
		W = W - lr*dw
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.00024, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	m,n = X_train.shape
	W = np.random.randn(n,1)
	## END TODO

	for i in range(max_iter):
		# print("Epoch #%d"%i)
		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		Y_pred = np.matmul(X_train,W)
		dw = np.matmul(np.transpose(X_train),(Y_pred-Y_train))/m + 2*reg*W
		W = W - lr*dw
		## END TODO
	# clf = Ridge(alpha=reg,solver = 'lsqr')
	# clf.fit(X_train,Y_train)
	# Y_pred1 = clf.predict(X_train)
	# Y_pred2 = clf.predict(X_test)
	# m1 = Y_test.shape[0]
	# print(np.sum(((Y_pred1-Y_train)**2))/(2*m), np.sum(((Y_pred2-Y_test)**2))/(2*m1))
	# print(train_mses[-1],test_mses[-1])
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (m,) array, where m is number of training samples
	'''

	## TODO
	R = np.diag(r)
	Y_new = np.matmul(R,Y)
	X_new = np.matmul(R,X)
	W = np.linalg.inv(np.matmul(X_new.T,X_new))
	W = np.matmul(np.matmul(W,X_new.T),Y_new)
	return W
	## END TODO
	

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	print(X.shape)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# print(np.linalg.norm(W_ridge))
	# print(train_mses[-1],test_mses[-1])
	# r = np.ones((X_train.shape[0],))
	# W = weighted_regression(X_train,Y_train,r)
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()


