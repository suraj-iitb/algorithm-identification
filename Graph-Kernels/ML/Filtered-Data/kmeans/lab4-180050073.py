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
		size_of_data = np.shape(data)[0]
		sample = np.random.choice(size_of_data, self.n_clusters, replace=False)
		self.cluster_centers = data[sample]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		distances = np.sum((self.cluster_centers-x)**2,axis=1)
		return np.argmin(distances)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			size_of_data = np.shape(data)[0]
			centers = np.copy(self.cluster_centers)
			labels = np.zeros((size_of_data,))
			prev_labels = np.zeros((size_of_data,1))

			### Update labels for each point
			squared_norm_data = np.sum(data*data, axis = 1).reshape(size_of_data,1)
			squared_norm_clusters = np.sum(self.cluster_centers*self.cluster_centers,axis = 1).reshape(1,self.n_clusters)
			distances = squared_norm_clusters+squared_norm_data - 2*np.matmul(data,np.transpose(self.cluster_centers))
			minimas = np.argmin(distances, axis=1)
			labels = minimas

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				boolvar = (labels==i)
				if np.any(boolvar):
					self.cluster_centers[i,:] = np.mean(data[boolvar,:],axis=0)


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

			if np.linalg.norm(centers - self.cluster_centers)<epsilon:
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

