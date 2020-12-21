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
		data_pts = np.random.choice(data.shape[0],self.n_clusters,replace=False)
		self.cluster_centers = data[data_pts]

		pass

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		Y = self.cluster_centers
		X = x.reshape(1,-1)
		dist = np.zeros((X.shape[0],Y.shape[0]))
		dist += np.sum(X*X,axis=1,keepdims=True)
		dist += np.sum(Y*Y,axis=1,keepdims=True).reshape(1,-1)
		dist -= 2 * X @ Y.T
		id_clust = np.argmin(dist,axis=1)
 		
		return id_clust.reshape(-1)[0]

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			data = data.reshape(data.shape[0],-1)

			### Update labels for each point
			dist = np.zeros((data.shape[0],self.cluster_centers.shape[0]))
			dist += np.sum(data*data,axis=1,keepdims=True)
			dist += np.sum(self.cluster_centers*self.cluster_centers,axis=1,keepdims=True).reshape(1,-1)
			dist -= 2 * data @ self.cluster_centers.T
			P_ij = dist - np.min(dist,axis=1).reshape(-1,1)
			P_ij[P_ij>0] = 1
			P_ij = 1 - P_ij
			sums = np.sum(P_ij,axis=1,keepdims=True)
			assert np.all(sums > 0)
			P_ij = P_ij/sums
			members = np.sum(P_ij,axis=0)
			### Update cluster centers
			new_clusters = P_ij.T @ data ## this should have dimension N_clusers X D
			### Note: If some cluster is empty, do not update the cluster center
			new_clusters[members!=0]= new_clusters[members!=0]/members[members!=0].reshape(-1,1)
			new_clusters[members==0]=self.cluster_centers[members==0]
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.max(np.linalg.norm(self.cluster_centers-new_clusters,axis=1)) < epsilon:
				self.cluster_centers = new_clusters
				break
			self.cluster_centers = new_clusters

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

