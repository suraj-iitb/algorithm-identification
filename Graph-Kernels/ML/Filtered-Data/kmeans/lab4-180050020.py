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
		d1 = self.cluster_centers.shape[0]
		for x in range(d1):
			self.cluster_centers[x,:] = data[x]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		d2 = self.cluster_centers.shape[0]
		min1 = np.zeros(d2)
		for y in range(d2):
			min1[y] = np.linalg.norm(x-self.cluster_centers[y,:])
		return np.argmin(min1)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			arr1 = np.zeros(data.shape[0])
			dummy1 = 0
			dummy2 = self.cluster_centers.copy()
			### Update labels for each point
			for x in range(data.shape[0]):
				arr1[x] = self.pred(data[x])

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for x in range(self.cluster_centers.shape[0]):
				if np.sum(arr1==x) != 0:
					dum1 = np.zeros(self.cluster_centers.shape[1])
					for y in range(arr1.shape[0]):
						if arr1[y]==x:
							dum1 = dum1 + data[y]
							dummy1 = dummy1 +1
					self.cluster_centers[x,:] = dum1/dummy1
					dummy1 = 0

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			for x in range(self.cluster_centers.shape[0]):
				if np.linalg.norm(dummy2[x,:]-self.cluster_centers[x,:]) <=0.0001:
					dummy1 = dummy1 + 1
			#print(it)
			if dummy1 == self.cluster_centers.shape[0]:
				#print(it)
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
	parser.add_argument('--image', default='3', choices=['1', '2', '3'])
	parser.add_argument('--k', default=2, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

