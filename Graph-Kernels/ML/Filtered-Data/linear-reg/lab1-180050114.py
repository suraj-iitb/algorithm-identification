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
	row,col = X.shape
	temp0 = np.matmul(X,W)-Y
	 
	mse = np.sum(temp0**2)/(2.0*row)
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.001, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	r,d = X_train.shape
	W = np.random.normal(0,0.01,size=(d, 1))
	# print(W)
	# END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO
# 
		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		temp0 = np.matmul(X_train,W)-Y_train
		temp1 = np.matmul(X_train.T,temp0)/r
		W = W-lr*temp1
		# print(W)
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.01, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	r,d = X_train.shape
	W = np.random.normal(0,1,size=(d, 1))	
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(X_train,Y_train,W) 
		test_mse = mse(X_test,Y_test,W) 
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		temp0 = np.matmul(X_train,W)-Y_train
		temp1 = (np.matmul(X_train.T,temp0)/r)+2*reg*W
		W = W-lr*temp1
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	# W =np.matmul( np.matmul(np.linalg.inv(np.matmul(X.T,X)),X.T),Y)
	R = np.zeros((len(r),len(r)))
	for i in range(len(r)):
		R[i][i]=r[i]
	W = np.linalg.inv(X.T @ R @ R @ X) @ X.T @ R @ R @ Y
	## END TODO
	return W


# X, Y = load_data2('data2.csv')
# X, Y = preprocess(X, Y)
# X_train, Y_train, X_test, Y_test = split_data(X, Y)
# W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
# print(train_mses)
# print(test_mses)
if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
	X_train, Y_train, X_test, Y_test = split_data(X, Y)

	W, train_mses, test_mses = ordinary_least_squares(X_train, Y_train, X_test, Y_test)
	# print(W)
	# W_ridge, train_mses, test_mses = ridge_regression(X_train, Y_train, X_test, Y_test, 10)
	# print(train_mses[-1])
	# print(test_mses[-1])
	# Plots
	plt.figure(figsize=(4,4))
	plt.plot(train_mses)
	plt.plot(test_mses)
	plt.legend(['Train MSE', 'Test MSE'])
	plt.xlabel('Iteration')
	plt.ylabel('MSE')
	plt.show()


