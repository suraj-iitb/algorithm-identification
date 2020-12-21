import argparse
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(5927)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters
		self.cluster_centers = np.zeros((n_clusters, D))

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data
		ind = np.random.choice(data.shape[0],self.n_clusters,replace=False)
		self.cluster_centers = data[ind]
		# print(self.cluster_centers.shape)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.sum((self.cluster_centers-x)**2,axis=1))
		### END TODO

	def train(self, data, max_iter=1000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variable
			# P = np.zeros((data.shape[0],self.n_clusters))
			
			# temp = np.apply_along_axis(self.pred,1,data)
			# print(temp)
			### Update labels for each point
			# for i in range(P.shape[0]):
				# P[i,temp[i]] = 1
			X2= np.sum(data**2,axis=1).reshape(data.shape[0],1)  @ np.ones((1,self.cluster_centers.shape[0]))
			Y2 = np.ones((data.shape[0],1)) @ np.sum(self.cluster_centers**2,axis=1).reshape(self.cluster_centers.shape[0],1).T
			kernel = X2 + Y2 - 2*data@self.cluster_centers.T
			curr_pred = np.argmin(kernel,axis=1)
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			# temp = np.sum(P,axis=0)
			# print(temp)
			# old = self.cluster_centers.copy()
			# for k in range(self.n_clusters):
			# 	fala = data[labels==k,:]
			# 	if (len(fala) > 0):
			# 		self.cluster_centers[k,:] = np.mean(fala,axis=0)
					# temp2[i] = np.sum(data*P[:,i].reshape(data.shape[0],1),axis=0)/temp[i]
			old = self.cluster_centers.copy()
			for k in range(self.n_clusters):
				temp = data[curr_pred==k,:]
				if (len(temp) > 0):
					self.cluster_centers[k,:] = np.sum(temp,axis=0)/len(temp)
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			# print(it)
			dist = np.linalg.norm(old-self.cluster_centers,axis=1)
			# print(dist)
			if(np.max(dist) < epsilon):
				break
			# self.cluster_centers=temp2
			### END TODO
		return it

	def replace_by_center(self, data):
		out = np.zeros_like(data)
		for i, x in enumerate(data):
			out[i] = self.cluster_centers[self.pred(x)]
		return out

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('--image', default='1', choices=['1', '2', '3'])
	parser.add_argument('--k', default=5, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

