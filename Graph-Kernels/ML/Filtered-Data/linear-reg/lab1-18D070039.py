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
	N=X.shape[0]
	#print(X)
	yp=np.matmul(X,W)
	diff=yp-Y
	summ=np.matmul(np.transpose(diff),diff)
	summ=summ/(2*N)
	mse=summ
	## END TODO

	return mse

def ordinary_least_squares(X_train, Y_train, X_test, Y_test, lr=0.008, max_iter=8000):
	train_mses = []
	test_mses = []
	## TODO: Initialize W using using random normal 
	m=X_train.shape[1]
	n=X_train.shape[0]
	
	W=np.random.normal(0.0,1.0,(m,1))
	## END TODO
	#print(W)
	for i in range(max_iter):
		## TODO: Compute train and test MSE
		train_mse=mse(X_train,Y_train,W)[0][0]
		
		test_mse=mse(X_test,Y_test,W)[0][0]
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		inn=(np.matmul(X_train,W))-Y_train	# Y'-Y
		inn=inn.reshape(n,1)				
		net=0
		op=W[0,:]
		net0=inn.sum(axis=0)/n				#sum(Y'-Y)
		inn2=np.repeat(inn,m,axis=1)
		sub=np.multiply(X_train,inn2)
		net=sub.sum(axis=0)/n
		net=net.reshape((m,1))
		W=W-lr*(net)
		W[0,:]=op-lr*net0
		
		'''
		for j in range(m):
			x=X_train[:,j]
			sub=np.multiply(x,inn)
			net=np.sum(sub)/n
			W[j]=W[j]-lr*(net)
			'''
		#print("two")
		## END TODO
	#print(train_mses[-1],test_mses[-1],sep=' ')


	return W, train_mses, test_mses

def ridge_regression(X_train, Y_train, X_test, Y_test, reg, lr=0.001, max_iter=1000):
	'''
	reg - regularization parameter (lambda in Q2.1 c)
	'''
	train_mses = []
	test_mses = []
	
	#print(reg.shape)
	## TODO: Initialize W using using random normal 
	m=X_train.shape[1]
	n=X_train.shape[0]
	
	W=np.random.normal(0.0,1.0,(m,1))
	
	## END TODO

	for i in range(max_iter):

		## TODO: Compute train and test MSE
		trmse=mse(X_train,Y_train,W)[0][0]
		temse=mse(X_test,Y_test,W)[0][0]
		add1=np.matmul(np.transpose(W),W)[0][0]
		add1=add1*reg
		train_mse=trmse
		test_mse=temse
		## END TODO

		train_mses.append(train_mse)
		test_mses.append(test_mse)

		## TODO: Update w and b using a single step of gradient descent
		inn=(np.matmul(X_train,W))-Y_train	# Y'-Y
		inn=inn.reshape(n,1)				
		net=0
		#op=W[0,:]
		# net0=inn.sum(axis=0)/n				#sum(Y'-Y)
		# net0+=2*W[0][0]*reg
		inn2=np.repeat(inn,m,axis=1)
		sub=np.multiply(X_train,inn2)
		net=sub.sum(axis=0)/n
		net=net.reshape((m,1))
		net+=2*reg*W
		W=W-lr*(net)
		#W[0,:]=op-lr*net0
		
		## END TODO
	return W, train_mses, test_mses

def weighted_regression(X, Y, r):
	'''
	Fill up this function for problem 3.
	Use closed form expression.
	r_train is a (n,) array, where n is number of training samples
	'''

	## TODO
	R=np.square(r)
	R=np.diag(R)
	inter=np.matmul(np.transpose(X),R)
	lhs=np.matmul(inter,X)
	rhs=np.matmul(inter,Y)
	lhsi=np.linalg.inv(lhs)
	W=np.matmul(lhsi,rhs)

	## END TODO
	return W

if __name__ == '__main__':
	# Load and split data
	X, Y = load_data2('data2.csv')
	X, Y = preprocess(X, Y)
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

