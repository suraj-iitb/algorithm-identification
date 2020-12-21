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
		indices = np.random.choice(data.shape[0],self.n_clusters, replace = False)
		self.cluster_centers = data[indices]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		mini = 99999999999999999999999999999
		val = -1;
		for i in range(self.cluster_centers.shape[0]):
			z = np.linalg.norm(self.cluster_centers[i]-x);
			if(mini>z):
				mini= z;
				val = i;
		return val
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			classes = {}

			for i in range(self.cluster_centers.shape[0]):
				classes[i] = []
			### Update labels for each point
			for x in data:
				classes[self.pred(x)].append(x)
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			past_cluster_centers = np.copy(self.cluster_centers);
			for i in range(self.cluster_centers.shape[0]):
				if(len(classes[i])!=0):
					self.cluster_centers[i] = np.average(classes[i],axis=0)


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			is1=1;
			for i in range(self.cluster_centers.shape[0]):
				if(np.linalg.norm(self.cluster_centers[i]-past_cluster_centers[i])>epsilon):
					is1 = 0;
			if(is1):
				break;
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
	parser.add_argument('--k', default=10, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

