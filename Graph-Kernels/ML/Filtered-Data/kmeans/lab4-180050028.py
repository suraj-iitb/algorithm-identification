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
		idx = np.random.randint(data.shape[0], size=self.n_clusters)
		self.cluster_centers =  data[idx,:]

		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		x_repeat = np.tile(x,(self.n_clusters,1))
		difs = x_repeat-self.cluster_centers
		distances = np.ndarray.flatten(np.linalg.norm(difs,axis=1))
		return np.argmin(distances)
		### END TODO

	def train(self, data, max_iter=20000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			labels = np.zeros(data.shape[0])
			d = data.shape[1]
			### Update labels for each point
			data_repeat = np.tile(data,self.n_clusters).reshape(self.n_clusters*data.shape[0],d)
			centers_repeat = np.tile(self.cluster_centers,(data.shape[0],1))
			difs  = data_repeat-centers_repeat
			norms = np.linalg.norm(difs, axis=1).reshape(data.shape[0],self.n_clusters)
			labels = np.ndarray.flatten(np.argmin(norms, axis=1))
			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			new_cluster_center = np.zeros((self.n_clusters,d))
		
			for i in range(self.n_clusters):
				indices = np.where(labels==i)[0]
				
				if (indices.shape[0]==0):
					new_cluster_center[i] = self.cluster_centers[i]
					continue
				sum = np.zeros(d)
				for k in range(indices.shape[0]):
					sum = sum + data[indices[k]]
				avg = sum/ indices.shape[0]
				new_cluster_center[i] = avg
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			diff = new_cluster_center-self.cluster_centers
			dist = np.linalg.norm(diff, axis=1)
			great = np.ndarray.flatten(np.where(dist>epsilon)[0])
			self.cluster_centers = new_cluster_center
			if(great.shape[0]==0):
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

