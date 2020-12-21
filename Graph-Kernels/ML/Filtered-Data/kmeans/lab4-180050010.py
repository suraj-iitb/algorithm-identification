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
		n = np.shape(data)[0]
		indices=np.random.choice(n,self.n_clusters,replace=False)
		self.cluster_centers = data[indices]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		temp=self.cluster_centers - x
		return np.argmin(np.sum(temp**2,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			old_cluster_centers = np.copy(self.cluster_centers) 



			### Update labels for each point

			current_labels = [self.pred(data[i]) for i in range(np.shape(data)[0])]

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center

			for i in range(self.n_clusters):
				indices = [ind for ind in range(len(current_labels)) if current_labels[ind]==i]
				if len(indices)!=0:
					cluster_members = data[indices]
					self.cluster_centers[i]=np.sum(cluster_members,axis=0)/(np.shape(cluster_members)[0])

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			temp=np.linalg.norm(old_cluster_centers-self.cluster_centers,axis=1)
			temp = temp < epsilon
			if np.sum(temp) == self.n_clusters:
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
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

