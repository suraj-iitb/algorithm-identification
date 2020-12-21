import argparse
import numpy as np
import matplotlib.pyplot as plt
from math import sqrt, floor

np.random.seed(5927)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters
		self.cluster_centers = np.zeros((n_clusters, D))

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data

		### ds : numpy array
        	### The dataset to be used for centroid initialization.
   		### k : int
        	### The desired number of clusters for which centroids are required.
    		### Returns
    		### -------
    		### centroids : numpy array
       		### Collection of k centroids as a numpy array.
    		### """
		def _get_mean(sums, step):
        		return sums/step
		n = np.shape(data)[1]
    		m = np.shape(data)[0]
    		### centroids = np.zeros((self, n))

    		composite = np.mat(np.sum(data, axis=1))
    		data = np.append(composite.T, data, axis=1)
    		data.sort(axis=0)

    		step = floor(m/self.n_clusters)
    		vfunc = np.vectorize(_get_mean)
	
   		for j in range(self.n_clusters):
        		if j == self.n_clusters-1:
            			self.cluster_centers[j:] = vfunc(np.sum(ds[j*step:,1:], axis=0), step)
        		else:
            			self.cluster_centers[j:] = vfunc(np.sum(ds[j*step:(j+1)*step,1:], axis=0), step)

    		return centroids
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables


			### Update labels for each point


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

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

