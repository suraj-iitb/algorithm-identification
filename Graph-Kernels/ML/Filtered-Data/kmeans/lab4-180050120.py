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
		m = data.shape[0]
		ids = np.random.randint(low=0, high=m, size=self.n_clusters)
		self.cluster_centers = data[ids]
		# print("cluster",self.cluster_centers.shape)
		### END TODO

	def pred(self, x):
		# print(x.shape)
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.sum(np.abs(x-self.cluster_centers)**2, axis = -1))


		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		# print("data",data.shape)
		for it in range(max_iter):
			# print(it)
			### TODO
			### Declare and initialize required variables

			num = np.zeros((self.n_clusters,1))
			new_cluster_centers = np.zeros(self.cluster_centers.shape)
			tmp = self.cluster_centers[: , np.newaxis, :]
			preds = np.argmin(np.sum((data - tmp)**2, axis=2),axis=0)
			### Update labels for each point
			m = data.shape[0]
			for i in range(self.n_clusters):
				new_cluster_centers[i, :] = np.sum(data[preds==i, :], axis=0)
				num[i] = np.sum(preds==i, axis=0)
			# m = data.shape[0]
			# for i in range(m):
			# 	id=self.pred(data[i])
			# 	num[id]+=1;
			# 	new_cluster_centers[id]+=data[i]

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center

			for i in range(self.n_clusters):
				if num[i]==0:
					new_cluster_centers[i]=self.cluster_centers[i]
				else:
					new_cluster_centers[i]=new_cluster_centers[i]/num[i]
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			stop_cond = np.sum((new_cluster_centers-self.cluster_centers)**2,axis=1) ** 0.5 < epsilon 
			self.cluster_centers = new_cluster_centers
			if np.all(stop_cond):
				break
			### END TODO
		return it
		# pass

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
	plt.savefig("3,10")
	# plt.show()

