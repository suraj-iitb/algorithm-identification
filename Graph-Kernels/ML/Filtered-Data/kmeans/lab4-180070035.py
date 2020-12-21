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
		num_samples = np.shape(data)[0]
		indices = np.random.choice(np.arange(num_samples), self.n_clusters, replace=False)
		self.cluster_centers = data[indices, :]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		a = (self.cluster_centers - x)**2
		a = np.sum(a, axis=1)
		return np.argmin(a)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			old_clusters = self.cluster_centers + 0
			labels = np.zeros(np.shape(data)[0])
			### Update labels for each point
			X2 = data**2
			Y2 = self.cluster_centers**2
			n = np.shape(X2)[0]
			m = np.shape(Y2)[0]
			d = np.shape(X2)[1]
			PX = np.ones((n, d))
			PY = np.ones((m, d))
			norms = X2 @ PY.T + PX @ Y2.T - 2*(data @ self.cluster_centers.T)
			labels = np.argmin(norms, axis=1)


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(self.n_clusters):
				points = data[labels == i]
				if np.shape(points)[0] == 0:
					continue
				self.cluster_centers[i, :] = np.mean(points, axis=0)



			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			d = (self.cluster_centers - old_clusters)**2
			diff = np.sum(d, axis=1)
			if np.max(diff) < epsilon**2:
				return it
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


