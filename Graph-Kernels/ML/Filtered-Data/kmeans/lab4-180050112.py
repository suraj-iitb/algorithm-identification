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
		self.cluster_centers = data[:self.n_clusters,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		temp = self.cluster_centers - x
		temp = temp**2
		temp = np.sum(temp,axis=1)
		return np.argmin(temp)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			labels = np.zeros((data.shape[0],1))
			temp_clustercenters = np.zeros_like(self.cluster_centers)
			temp_clustercount = np.zeros((self.n_clusters,1))

			### Update labels for each point
			for i in range(data.shape[0]):
				la = self.pred(data[i])
				labels[i] = la
				temp_clustercenters[la] = temp_clustercenters[la] + data[i,:] 
				temp_clustercount[la] = temp_clustercount[la]+1;

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				if temp_clustercount[i]!=0:
					temp_clustercenters[i,:] = temp_clustercenters[i,:] / temp_clustercount[i] 
				else:
					temp_clustercenters[i,:] = self.cluster_centers[i,:]

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			temp = (temp_clustercenters - self.cluster_centers)**2
			temp = np.sum(temp,axis=1)
			temp = np.sqrt(temp)
			temp = temp >= epsilon
			if np.sum(temp)==0:
				self.cluster_centers = temp_clustercenters
				break
			else:
				self.cluster_centers = temp_clustercenters
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

