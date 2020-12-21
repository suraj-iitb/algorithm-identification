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
		indices = np.random.permutation(np.arange(data.shape[0]))[:self.n_clusters]
		self.cluster_centers = np.array([data[i] for i in indices])
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		A = self.cluster_centers - x
		A = np.square(A)
		A = np.sum(A,axis=1)
		return np.argmin(A)

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# print(it)
			labels = np.zeros((data.shape[0],1))

			### Update labels for each point
			for i in range(data.shape[0]):
				labels[i] = self.pred(data[i])

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			nn_clusters = np.zeros((self.n_clusters,data.shape[1]))
			for i in range(self.n_clusters):
				k=0
				nsum = np.zeros(data.shape[1])
				for j in range(labels.shape[0]):
					if labels[j]==i:
						k+=1
						nsum+=data[j]
				if k!=0:
					# print(i,nsum,k)
					# print(nn_clusters[i])
					nn_clusters[i]=nsum/k
					# print(nn_clusters[i])
				else:
					nn_clusters[i]=self.cluster_centers[i]


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			# print(np.linalg.norm(nn_clusters-self.cluster_centers))
			if np.linalg.norm(nn_clusters-self.cluster_centers) < epsilon:
				break
			self.cluster_centers = nn_clusters

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

