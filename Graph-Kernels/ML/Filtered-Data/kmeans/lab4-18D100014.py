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

		data1 = np.arange(data.shape[0])
		indices = np.random.choice(data1, self.n_clusters, False)

		self.cluster_centers = data[indices]

		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		l=self.cluster_centers.shape[0]

		dist=np.zeros((l,1))

		for i in range(l):
			distance=np.linalg.norm(self.cluster_centers[i] - x)
			dist[i]=distance

		return np.argmin(dist)

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables

			num_points = data.shape[0]
			#print(num_points)
			labels = np.zeros((num_points,1), dtype=int)
			dist = np.zeros((num_points,self.n_clusters))

			num = np.zeros((self.n_clusters,data.shape[1]))
			den = np.zeros((self.n_clusters,1))

			### Update labels for each point

			#A=data[:, np.newaxis] - self.cluster_centers
			#A=np.linalg.norm(A, axis=2)

			for i in range(self.n_clusters):
				temp = data-self.cluster_centers[i]
				dist[:,i] = np.linalg.norm(temp, axis=1)

			#print("yo1")
			#lol=(dist==A)
			#print(np.sum(lol))

			labels=np.argmin(dist,axis=1)

			'''for i in range(num_points):
				labels[i] = self.pred(data[i])'''

			### Update cluster centers

			for i in range(self.n_clusters):
				indices = np.argwhere(labels==i)
				num[i] = np.sum(data[indices],axis=0)
				den[i] = indices.shape[0]

			#print("yo2")

			'''for i in range(num_points):
				num[labels[i]] = num[labels[i]] + data[i]
				den[labels[i]] = den[labels[i]] + 1'''


			### Note: If some cluster is empty, do not update the cluster center

			new_clusters = np.zeros(self.cluster_centers.shape)

			for i in range(self.n_clusters):
				if den[i]!=0 :
					new_clusters[i] = num[i]/den[i]
				else:
					new_clusters[i] = self.cluster_centers[i]

			#print("yo3")

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

			diff = new_clusters - self.cluster_centers
			norm = np.linalg.norm(diff)

			self.cluster_centers = new_clusters

			if norm<epsilon:
				break

			#print("yo4")

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

	image = plt.imread("data/"+args.image+".png")
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

