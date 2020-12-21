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
	rows =  X.shape[0]
	sum = 0.0
	for i in range(rows):
		y = np.transpose(W).dot(np.transpose(X[i]))
		sum+= (1/(2*rows))*(y-Y)*(y-Y)
	return sum
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.00001, max_iter=2000):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	#w =np.transpose(np.random.normal(len(X_train[0])))
	l = []
	for i in range(len(X_train[0])):
		l.append(np.random.normal())
	w= np.array(l)
	## END TODO
	rows = len(X_train)

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse = mse(np.array(X_train),Y_train,w)
		test_mse = mse(np.array(X_test), Y_test,w)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		for j in range(w.shape[0]):
			sum =0;
			for i in range(rows):
				y = np.transpose(w).dot(np.transpose(X[i]))
				sum+= (y-Y[i])*X[i][j]
			w[j] -= lr*(1/rows)*sum
		
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.00001, max_iter=2000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 

	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE

		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent

		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	#print(X)
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

