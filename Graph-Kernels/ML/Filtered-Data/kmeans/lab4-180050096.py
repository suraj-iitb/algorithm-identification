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
		self.cluster_centers = data[np.random.choice(data.shape[0],self.n_clusters,replace = False)]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		return np.argmin(np.sum(np.square(self.cluster_centers - x), axis = 1), axis = 0)
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):	
		### TODO
		temp = np.zeros((self.n_clusters, data.shape[1]))
		for it in range(max_iter):
			### Declare and initialize required variables
			new_cluster_centers = np.zeros((self.n_clusters, data.shape[1]))
			
			label_count = np.zeros((self.n_clusters,1))
			### Update labels for each point
			for i in range(data.shape[0]):
				label = self.pred(data[i:i+1,:])
				new_cluster_centers[label] += data[i]
				label_count[label,0] += 1
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			emp = label_count == 0
			emp1 = np.arange(self.n_clusters).reshape(-1,1)[np.logical_not(emp)]
			emp = np.arange(self.n_clusters).reshape(-1,1)[emp]
			new_cluster_centers[emp] = self.cluster_centers[emp]
			new_cluster_centers[emp1] /= label_count[emp1]
			### Check for convergence
			temp = self.cluster_centers
			self.cluster_centers = new_cluster_centers
			new_cluster_centers = temp
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			if np.all(np.sum(np.square(self.cluster_centers - new_cluster_centers), axis = 1) < epsilon):
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

	# for i in range(1,4):
	# 	fig,ax = plt.subplots(nrows=1,ncols=3, figsize=(9,3))
	# 	image = plt.imread(f'data/{i}.png')
	# 	for j,k in enumerate([2,5,10]):
	# 		x = image.reshape(-1, 3)
	# 		kmeans = KMeans(D=3, n_clusters=k)
	# 		kmeans.init_clusters(x)
	# 		kmeans.train(x)
	# 		out = kmeans.replace_by_center(x)
	# 		ax[j].imshow(out.reshape(image.shape))
	# 		ax[j].set_title(f'k={k}')
	# 	plt.savefig(f'image{i}.png')
	# 	plt.show()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

