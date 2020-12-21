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
		local_data = np.unique(data,axis = 0)
		pos = np.random.choice(local_data.shape[0], self.n_clusters, replace=False)
		self.cluster_centers = local_data[pos]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		centers = self.cluster_centers
		diff = np.sum(np.power((centers - x),2),axis = 1)
		arggmin = np.argmin(diff)
		return arggmin
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			centers = np.copy(self.cluster_centers)

			### Update labels for each point
			positions = np.apply_along_axis(self.pred,1,data)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for i in range(0,self.n_clusters):
				data_pos = np.where(positions == i)
				spliced = data[data_pos]
				n = spliced.shape[0]
				# print(i)
				if n != 0:
					centers[i] = sum(spliced)/n
				pass

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			testing = np.sum(np.power((centers-self.cluster_centers),2),axis = 1)
			if np.all(np.sqrt(testing) < epsilon):
				self.cluster_centers = centers
				break
				pass
			self.cluster_centers = centers
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

