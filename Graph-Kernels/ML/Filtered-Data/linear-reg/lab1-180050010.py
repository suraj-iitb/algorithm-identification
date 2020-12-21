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
	W = (np.reshape(W,(1,n_features)))[0]
	Y = (np.reshape(Y,(1,n_samples)))[0]
	predictions = np.dot(X,W)
	error_vec = Y-predictions 
	error=(np.sum(error_vec*error_vec))/(2*n_samples)
	return error
	
	## END TODO

	return mse

def nabla(X,Y,W,regul):
    # returns the nabla of the error function with respect to W
	# lambda =0 for OLS and can be set for ridge regression
	n_samples = np.shape(X)[0]
	n_features = np.shape(X)[1]
	W = (np.reshape(W,(1,n_features)))[0]
	Y = (np.reshape(Y,(1,n_samples)))[0]
	predictions = np.dot(X,W)
	yihat_yi = (predictions-Y)/n_samples
	final_vec=np.zeros((n_features,1))
	for i in range(n_features):
		final_vec[i,0] = np.dot(yihat_yi,X[:,i])
	W = np.reshape(W,(n_features,1))
	W = 2*regul*W 
	final_vec =final_vec+W
	return final_vec


def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.05, max_iter=3500):
	train_mses = []
	test_mses = []

	## TODO: Initialize W using using random normal 
	n_samples = np.shape(X_train)[0]
	n_features = np.shape(X_train)[1]
	W = np.random.normal(size=(n_features,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		train_mse= mse(X_train,Y_train,W)
		test_mse = mse(X_test,Y_test,W)
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		nabla_val = nabla(X_train,Y_train,W,0)
		W = W - lr*nabla_val
		## END TODO

	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.03, max_iter=3500):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []
	decay_rate = 0.05
	## TODO: Initialize W using using random normal 
	n_samples = np.shape(X_train)[0]
	n_features = np.shape(X_train)[1]
	W = np.random.normal(size=(n_features,1))
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		reg_term = reg*((np.linalg.norm(W))**2)
		train_mse = mse(X_train,Y_train,W)  + reg_term
		test_mse = mse(X_test,Y_test,W) + reg_term
		## END TODO

		train_mses.append(train_mse-reg_term)
		test_mses.append(test_mse-reg_term)

		## TODO: Update w and b using a single step of gradient descent
		nabla_val = nabla(X_train,Y_train,W,reg)
		new_W=[]
		while True:
			new_W = W - lr*nabla_val
			new_reg_term = reg*((np.linalg.norm(new_W))**2)
			new_mse = mse(X_train,Y_train,new_W)+new_reg_term
			if new_mse > train_mse:
				lr =lr - decay_rate*lr
			else:
				W = new_W				
				break
		
    			
		## END TODO

	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	n_samples = np.shape(X)[0]
	n_features = np.shape(X)[1]
	D = np.zeros((n_samples,n_samples))
	r= np.reshape(r,(1,n_samples))[0]
	np.fill_diagonal(D,r)
	D2 = np.matmul(D,D)
	temp=np.matmul(np.matmul(np.transpose(X),D2),X)
	W=np.matmul(np.matmul(np.matmul(np.linalg.inv(temp),np.transpose(X)), D2),Y)
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

