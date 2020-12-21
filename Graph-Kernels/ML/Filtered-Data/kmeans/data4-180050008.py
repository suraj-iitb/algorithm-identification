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
		self.cluster_centers = data[np.random.choice(data.shape[0],self.n_clusters, replace=False)]
		# print(self.cluster_centers.shape)
		# for i in range(self.n_clusters):
		# 	self.cluster_centers[i] = data[i]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		distances = [np.linalg.norm(x-centroid) for centroid in self.cluster_centers]
		classe = distances.index(min(distances))
		return classe # doubt
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			self.classifications = {}

			for i in range(self.n_clusters):
				self.classifications[i] = []

			### Update labels for each point
			for featureset in data:
				distances = [np.linalg.norm(featureset-centroid) for centroid in self.cluster_centers]
				classification = distances.index(min(distances))
				self.classifications[classification].append(featureset)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			# print("before",self.cluster_centers)
			prev_centroids = np.copy(self.cluster_centers)

			for classification in self.classifications:
				if(len(self.classifications[classification])==0):
					continue

				# print("rhs",np.average(self.classifications[classification],axis=0).shape)
				# print("lhs",self.cluster_centers[classification].shape)
				self.cluster_centers[classification] = np.average(self.classifications[classification],axis=0)


			# print("after",self.cluster_centers)
			# print("prev",prev_centroids)
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			optimized = True
			
			for c in range(self.n_clusters):
				original_centroid = prev_centroids[c]
				current_centroid = self.cluster_centers[c]
				# print("org",original_centroid)
				# print("new",current_centroid)
				if np.linalg.norm(current_centroid-original_centroid) >= epsilon:
					# print("opt",np.sum((current_centroid-original_centroid)/original_centroid*100.0))
					optimized = False
					
			if optimized:
				# print("break")
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
