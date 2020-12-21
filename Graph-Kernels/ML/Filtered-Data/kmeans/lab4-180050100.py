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
		N = data.shape[0]
		ind = np.arange(N)
		np.random.shuffle(ind)
		self.cluster_centers = data[ind[:self.n_clusters], :] 
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		A = self.cluster_centers-x.T
		dist = np.linalg.norm(A, axis=1)
		ind = np.argmin(dist)
		return ind
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			prev = self.cluster_centers

			### Update labels for each point
			#f = lambda x: self.pred(x)
			A = np.linalg.norm(self.cluster_centers, axis=1)[:, np.newaxis]
			B = np.dot(self.cluster_centers, data.T)
			C = np.linalg.norm(data, axis=1)[:, np.newaxis]
			D = np.square(A)-2*B+np.square(C.T)

			upd = np.argmin(D, axis=0)
			# upd = np.array([self.pred(d) for d in data])
			# print(upd)
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			cluster_ind = [data[upd==i] for i in range(self.n_clusters)]
			# print(cluster_ind[0].shape)
			g = lambda x, y: y if len(x)==0 else np.mean(x, axis=0)
			cluster_upd = np.array([g(cluster_ind[i], self.cluster_centers[i]) for i in range(self.n_clusters)])
			self.cluster_centers=cluster_upd
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.max(np.linalg.norm(prev-self.cluster_centers, axis=1))<epsilon:
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
	parser.add_argument('--k', default=9, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

	# fig,ax = plt.subplots(nrows=1,ncols=3, figsize=(9,3))
	# kmeans = KMeans(D=3, n_clusters=2)
	# kmeans.init_clusters(x)
	# kmeans.train(x)
	# out = kmeans.replace_by_center(x)
	# ax[0].imshow(out.reshape(image.shape))
	# ax[0].set_title("k=2")
	# kmeans = KMeans(D=3, n_clusters=5)
	# kmeans.init_clusters(x)
	# kmeans.train(x)
	# out = kmeans.replace_by_center(x)
	# ax[1].imshow(out.reshape(image.shape))
	# ax[1].set_title("k=5")
	# kmeans = KMeans(D=3, n_clusters=10)
	# kmeans.init_clusters(x)
	# kmeans.train(x)
	# out = kmeans.replace_by_center(x)
	# ax[2].imshow(out.reshape(image.shape))
	# ax[2].set_title("k=10")

	# plt.show()