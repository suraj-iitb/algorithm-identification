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
		# D=self.cluster_centers.shape[1]
		# self.cluster_centers=np.random.rand(self.n_clusters, D)
		# self.memberships_one_hot=np.zeros((self.n_clusters,data.shape[0]),dtype=int)
		# self.memberships_vec=np.zeros((data.shape[0],1),dtype=int)
		# # print(self.memberships_one_hot.shape)
		# for i in range(data.shape[0]):
		# 	mem=np.argmin(np.linalg.norm(data[i]-self.cluster_centers,axis=1))
		# 	self.memberships_vec[i]=mem
		# 	# print(self.memberships_one_hot.shape)
		# 	self.memberships_one_hot[mem][i]=1
		# nums=np.random.uniform(0,data.shape[0],self.n_clusters)
		t1=np.arange(data.shape[0])
		np.random.shuffle(t1)
		for i in range(self.n_clusters):
			self.cluster_centers[i]=data[t1[i]]
		# print(D)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		#edit begins
		#assuming x is of shape (D,)
		x.shape=(x.shape[0],)
		return np.argmin(np.linalg.norm(x-self.cluster_centers,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables

			memberships_one_hot=np.zeros((self.n_clusters,data.shape[0]),dtype=int)
			prev_cluster_centers=np.copy(self.cluster_centers)
			### Update labels for each point
			for i in range(data.shape[0]):
				mem=np.argmin(np.linalg.norm(data[i]-self.cluster_centers,axis=1))
				memberships_one_hot[mem][i]=1
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			denom=np.sum(memberships_one_hot,axis=1)

			for i in range(self.n_clusters):
				if denom[i]!=0:
					self.cluster_centers[i]=np.dot(data.T,memberships_one_hot[i])
					self.cluster_centers[i]/=denom[i]
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			temp=np.linalg.norm(self.cluster_centers-prev_cluster_centers,axis=1)
			if np.max(temp)<epsilon:
				break
			# if np.linalg.norm(prev_cluster_centers-self.cluster_centers)<epsilon:
			# 	break
			### END TODO
		# print(it)
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

