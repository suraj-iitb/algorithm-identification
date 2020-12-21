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
		m = data.shape[0]
		ids = np.random.choice(np.arange(m), size=self.n_clusters, replace=False)
		self.cluster_centers = data[ids]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		tmp = self.cluster_centers - x
		tmp = np.linalg.norm(tmp, axis=1)
		return np.argmin(tmp)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			# if(it%100==0):
			# 	print(it)
			### Declare and initialize required variables
			old_clusters = self.cluster_centers.copy()
			### Update labels for each point
			a = self.cluster_centers.reshape((self.n_clusters, 1, self.cluster_centers.shape[1]))
			b = data.reshape((1, data.shape[0], data.shape[1]))
			tmp = np.linalg.norm(a-b, axis=2)
			ids = np.argmin(tmp, axis=0)
			# print(ids.shape)

			### Update cluster centers
			for i in range(self.n_clusters):
				if(np.sum(ids==i)==0):	
					pass
				else:
					self.cluster_centers[i] = np.mean(data[ids==i], axis=0)
			### Note: If some cluster is empty, do not update the cluster center

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			checker = np.linalg.norm(old_clusters-self.cluster_centers, axis=1)
			if(np.max(checker)<epsilon):
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
	# image = plt.imread("data/{}.png".format(args.image))
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	# print(x)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

