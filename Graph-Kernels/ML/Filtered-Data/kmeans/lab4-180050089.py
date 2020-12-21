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
		ids = np.random.randint(data.shape[0],size=self.n_clusters)
		self.cluster_centers = data[ids]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		y = np.sum((self.cluster_centers - x.reshape(1, -1)) ** 2, axis=1)
		return np.argmin(y)
		### END TODO

	def train(self, data, max_iter=1000, epsilon=1e-4):
		# print(data,self.cluster_centers)
		for it in range(max_iter):
			### TODO
			m = np.zeros((self.n_clusters, data.shape[0]))
			new_clus = np.copy(self.cluster_centers)
			### Declare and initialize required variables
			# c,D with n,D
			# c, D , 1 with 1 , D , n
			# c, D, n -> c,n

			### Update labels for each point
			m[np.argmin(np.sum((self.cluster_centers.reshape(self.n_clusters, -1, 1) - np.transpose(data).reshape(1, data.shape[1], data.shape[0])) ** 2, axis=1), axis=0), np.arange(data.shape[0])] = 1
			# print(m)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			s = np.sum(m, axis=1, keepdims=True)
			ids = np.flatnonzero(s)
			new_clus[ids] = ((m@data)[ids]/s[ids])

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.all(np.sum((new_clus - self.cluster_centers) ** 2, axis=1) < epsilon ** 2):
				self.cluster_centers = new_clus
				break
			self.cluster_centers = new_clus
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
	# print(x.shape)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

