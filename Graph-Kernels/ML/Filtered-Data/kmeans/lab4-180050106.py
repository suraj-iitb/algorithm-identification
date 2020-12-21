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
		idx = np.random.choice(data.shape[0],self.n_clusters,replace=False)
		self.cluster_centers = data[idx,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.linalg.norm(self.cluster_centers - x.reshape(1,len(x)),axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables


			### Update labels for each point
			X = data
			Y = self.cluster_centers
			Xn=X*X @ np.ones((X.shape[1],1))
			Yn=Y*Y @ np.ones((Y.shape[1],1))
			K = Xn@np.ones((1,Y.shape[0])) + np.ones((X.shape[0],1))@Yn.T - 2*X@Y.T
			labels = np.argmin(K,axis=1)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			old_centers = self.cluster_centers.copy()
			for k in range(self.n_clusters):
				temp = data[labels==k,:]
				if (len(temp)>0):
					self.cluster_centers[k,:]=np.mean(temp,axis=0)

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.max(np.linalg.norm(self.cluster_centers-old_centers,axis=1))<epsilon:
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
	# k_list=[2,5,10]
	# fig,ax=plt.subplots(nrows=1,ncols=len(k_list),figsize=(10,3))
	# for i in range(len(k_list)):
	# 	k = k_list[i]
	# 	kmeans = KMeans(D=3, n_clusters=k)
	# 	kmeans.init_clusters(x)
	# 	kmeans.train(x)
	# 	out = kmeans.replace_by_center(x)
	# 	ax[i].imshow(out.reshape(image.shape))
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()
