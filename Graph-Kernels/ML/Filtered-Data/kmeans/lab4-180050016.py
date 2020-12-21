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
		n,d = data.shape
		rand_indices = np.random.permutation(n)[:self.n_clusters]

		self.cluster_centers = data[rand_indices,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		distances = np.sum(np.square(self.cluster_centers - x), axis=1)

		return np.argmin(distances)
		### END TODO


	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# self.init_clusters(data)
			# print(it)
			mappings = np.zeros((data.shape[0], self.n_clusters))
			# print(self.cluster_centers)

			### Update labels for each point
			for i in range(data.shape[0]):
				cluster_id = self.pred(data[i])
				# mappings[i,:] = np.zeros((1, self.n_clusters))
				mappings[i,cluster_id] = 1

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			# cluster_centres_upd = self.cluster_centers
			n,d = self.cluster_centers.shape
			cluster_centres_upd = self.cluster_centers.copy()
			# print(cluster_centres_upd)

			for i in range(self.n_clusters):
				if(sum(mappings[:,i]) > 0):
					cluster_centres_upd[i,:] = (mappings[:,i].T @ data) / sum(mappings[:,i])

			# print(cluster_centres_upd)
			# print(self.cluster_centers)
			# print(self.cluster_centers - cluster_centres_upd)

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			# conv = False
			dist = np.linalg.norm(self.cluster_centers - cluster_centres_upd, axis=1)

			self.cluster_centers = cluster_centres_upd
			# print(dist)

			if np.all(dist < epsilon):
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

