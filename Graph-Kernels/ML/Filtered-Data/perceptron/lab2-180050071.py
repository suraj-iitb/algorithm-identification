import numpy as np
from matplotlib import pyplot as plt
import argparse
from math import log

def get_data(dataset,num_train_samples=-1):
	datasets = ['D1', 'D2']
	assert dataset in datasets, "Dataset {dataset} not supported. Supported datasets {datasets}"
	X_train = np.loadtxt(f'data/{dataset}/training_data')
	Y_train = np.loadtxt(f'data/{dataset}/training_labels', dtype=int)
	X_test = np.loadtxt(f'data/{dataset}/test_data')
	Y_test = np.loadtxt(f'data/{dataset}/test_labels', dtype=int)

	return X_train[:num_train_samples,:], Y_train[:num_train_samples], X_test, Y_test

class Perceptron():
	def __init__(self, C, D):
		'''
		C - number of classes -> y
		D - number of features 
		'''
		self.C = C
		self.weights = np.zeros((C, D))
		
	def pred(self, x):
		'''
		x - numpy array of shape (D,)
		'''
		### TODO: Return predicted class for x
		best_val=-1
		best_class=-1
		w=self.weights
		for i in range(self.C):
			val=np.matmul(w[i,:],x)
			if(val>=best_val):
				best_val=val
				best_class=i
		return best_class
		### END TODO

	def train(self, X, Y, max_iter=2):
		w=self.weights
		for j in range(max_iter):
			# print(j)
			for i in range(X.shape[0]):
				### TODO: Update weights
				V=X[i,:].transpose()
				Y_hat=self.pred(V)
				if(Y_hat!=Y[i]):
					w[Y[i],:]=w[Y[i],:]+X[i,:]
					w[Y_hat,:]=w[Y_hat,:]-X[i,:]
		self.weights=w
				### END TODO

	def eval(self, X, Y):
		n_samples = X.shape[0]
		correct = 0
		for i in range(X.shape[0]):
			if self.pred(X[i]) == Y[i]:
				correct += 1
		return correct/n_samples

if __name__ == '__main__':
	parser = argparse.ArgumentParser(description='Problem 4')
	parser.add_argument('--num_samples', type=int, default=-1,
					help='Number of samples to train on')
	args = parser.parse_args()
	
	num_train_samples = args.num_samples

	X_train, Y_train, X_test, Y_test = get_data('D1',num_train_samples)

	C = max(np.max(Y_train), np.max(Y_test))+1
	D = X_train.shape[1]

	perceptron = Perceptron(C, D)
	perceptron.train(X_train, Y_train)
	acc = perceptron.eval(X_test, Y_test)
	test_error=1-acc
	print(f'Test Accuracy: {acc}')
	# max_iter=[]
	# test_acc=[]
	# for i in range(1,10):
	# 	max_iter.append(i)	
	# 	perceptron.train(X_train, Y_train,i)
	# 	acc = perceptron.eval(X_test, Y_test)
	# 	print(f'Test Accuracy: {acc}')
	# 	test_acc.append(acc)
	# plt.plot(max_iter,test_acc)
	# plt.show()

	file0=open("train_num.txt",'a')
	file0.write(str(num_train_samples))
	file0.write(" ")
	file0.write(str(test_error))
	file0.write("\n")
	file0.close()

	file0=open("train_num.txt",'r')
	x=[]
	y=[]
	for line in file0:
		fields=line.split(" ")
		field0=log(int(fields[0]))
		x.append(field0)
		field1=float(fields[1])
		y.append(field1)
	file0.close()

	plt.plot(x,y)
	plt.xlabel("log(Number of training samples)")
	plt.ylabel("Test Error")
	plt.title("Error Plot")
	plt.show()