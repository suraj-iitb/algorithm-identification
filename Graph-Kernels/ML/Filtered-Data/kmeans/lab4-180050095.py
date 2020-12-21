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
		indices = np.random.choice(range(data.shape[0]), self.n_clusters, replace=False)
		self.cluster_centers = data[indices][:]

		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		dist_arr = (self.cluster_centers - x)**2
		dist_arr = np.sum(dist_arr,axis=-1)
		return np.argmin(dist_arr)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			out = self.replace_by_center(data)
			old = self.cluster_centers.copy()
			

			### Update labels for each point
			### Update cluster centers
			for i in range(self.n_clusters):
				# y = 0
				# x = np.zeros_like(self.cluster_centers[i])
				
				z = np.all(out == self.cluster_centers[i],axis=1)
				if np.any(z):	
					self.cluster_centers[i] = np.mean(data[np.all(out == self.cluster_centers[i],axis=1)],axis=0)
				# for j in range(data.shape[0]):
				# 	if np.all(out[j] == self.cluster_centers[i]):
				# 		x = x + data[j]
				# 		y = y + 1

				# if y > 0:
				# 	self.cluster_centers[i] = x/y
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			distance = np.sqrt(np.sum((old - self.cluster_centers)**2,axis=-1))
			if np.all(distance < epsilon):
				break;
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

