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
		l = len(data)
		#print(l)
		indices = np.random.choice(l,self.n_clusters,replace=False)
		#print(indices)
		for i in range(self.n_clusters):
			self.cluster_centers[i] = data[indices[i]]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		dist = np.sum((self.cluster_centers-x)**2,axis=1)
		return np.argmin(dist)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			### Update labels for each point
			labels = np.array([self.pred(x) for x in data])
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			b = np.array([(labels == i).astype(np.int) for i in range(self.n_clusters)])
			new_centers = np.array([np.sum((data.T*b[i]).T,axis = 0)/np.sum(b[i]) if np.sum(b[i])>0 else self.cluster_centers[i] for i in range(len(b))])
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			dist = np.array([np.linalg.norm(new_centers[i]-self.cluster_centers[i]) for i in range(new_centers.shape[0])])
			if np.all(dist<epsilon):
				break
			self.cluster_centers = new_centers
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

