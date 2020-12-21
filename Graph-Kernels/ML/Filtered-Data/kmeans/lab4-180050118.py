import argparse
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(5927)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters #5
		self.cluster_centers = np.zeros((n_clusters, D)) # (5,3) => shape

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data
		self.cluster_centers = np.random.rand(self.n_clusters,self.cluster_centers.shape[1])
		pass
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1))
		pass
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			m = data.shape[0] #(m,3)
			k = self.n_clusters
			if(it == 0):
				self.Pij = np.zeros((k,m))
			old_clusters = self.cluster_centers
			### Update labels for each point
				
			for i in range(m):
				dist = np.linalg.norm(self.cluster_centers - data[i],axis=1)
				min_i = np.argmin(dist)
				self.Pij[:,i] = [0]*self.n_clusters
				self.Pij[min_i,i] = 1

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(k):
				if(np.max(self.Pij[i]) == 1):
					temp = self.Pij[i]@data
					cluster = temp/np.sum(self.Pij[i])
					self.cluster_centers[i] = cluster

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dist = np.linalg.norm(old_clusters-self.cluster_centers,axis=1)
			if((dist < epsilon).all):
				break
			### END TODO

		return it
		

	def replace_by_center(self, data):
		out = np.zeros_like(data)
		for i, x in enumerate(data):
			out[i] = self.cluster_centers[self.pred(x)]
		return out

if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('--image', default='3', choices=['1', '2', '3'])
	parser.add_argument('--k', default=10, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

