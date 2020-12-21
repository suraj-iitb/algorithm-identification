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
		m1 = data.shape[0]
		self.cluster_centers = data[np.random.permutation(m1)[:self.n_clusters], :]
		### Initialize cluster_centers using n_clusters points sampled from data
		### END TODO


	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		distance = 1e9
		index = -1
		for i in range(self.n_clusters):
			d = np.linalg.norm(self.cluster_centers[i] - x)
			if(d < distance):
				index = i
				distance = d
		return index

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			temp_cluster_centers = np.copy(self.cluster_centers)
			### Update labels for each point
			labels = np.array([self.pred(data[i,:]) for i in range(data.shape[0])])
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center

			for k in range(self.n_clusters):
				points_ind = (labels == k)
				if np.sum(points_ind) > 0:
					self.cluster_centers[k] = np.sum(data[points_ind], axis=0) / np.sum(points_ind)
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			bk = True
			for k in range(self.n_clusters):
				if(np.linalg.norm(self.cluster_centers[k]-temp_cluster_centers[k]) >= epsilon):
					bk = False
			if(bk):
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

