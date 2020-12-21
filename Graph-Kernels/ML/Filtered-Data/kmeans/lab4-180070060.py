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
		self.cluster_centers = data[np.random.randint(data.shape[0], size = (self.n_clusters))]
		assert self.cluster_centers.shape == (self.n_clusters, 3) 			
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		dist = ((x[np.newaxis] - self.cluster_centers)**2).sum(axis= 1)
		return dist.argmin()

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			positions = []
			for _ in range(self.n_clusters):
				positions.append(None)
			### Update labels for each point
			for x in data:
				pos = self.pred(x)
				if positions[pos] is None:
					positions[pos] = x[np.newaxis]
				else:
					positions[pos] = np.row_stack((positions[pos],x[np.newaxis]))
				
			pass

			### Update cluster centers
			new_index_center = np.zeros(self.cluster_centers.shape)
			i = 0
			for position in positions:
				assert i < self.n_clusters
				if position is None:
					new_index_center[i] = self.cluster_centers[i]
				else:
					new_index_center[i] = position.sum(axis = 0)/position.shape[0]
				i+=1

			
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			diff_val = ((new_index_center - self.cluster_centers)**2).sum(axis = 1)
			num_great_ep = diff_val >= epsilon
			self.cluster_centers = new_index_center
			if np.sum(num_great_ep) == 0:
				break
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

