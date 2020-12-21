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
		index = np.random.choice(data.shape[0],self.n_clusters)
		self.cluster_centers = data[index].reshape(self.cluster_centers.shape)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		c = np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1),axis=0)
		return c
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			n = data.shape[0]
			temp = []
			for i in range(self.n_clusters):
				temp.append([])
			new_clusters = []
			### Update temp for each point
			for i in range(n):
				temp[self.pred(data[i,:])].append(data[i,:])
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			for index,lst in enumerate(temp):
				if not(lst):
					new_clusters.append(self.cluster_centers[index])
				else:
					new_clusters.append(np.sum(lst,axis=0)/len(lst))
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			next_ans = np.array(new_clusters).reshape(self.cluster_centers.shape)
			dist = np.sqrt(np.sum((next_ans-self.cluster_centers)**2, axis=1))
			if np.all(np.linalg.norm(dist, np.inf) < epsilon):
				break
			self.cluster_centers = next_ans
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

