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
		# print(data.shape)
		# print(self.cluster_centers.shape)
		self.cluster_centers = data[np.random.choice(data.shape[0],self.n_clusters, replace=False),:]
		# print(cluster_centers)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		distances = [np.linalg.norm(x-centroid) for centroid in self.cluster_centers]
		classification = distances.index(min(distances))
		# print(classification)
		return classification
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			self.classifications = {}

			for i in range(self.n_clusters):
				self.classifications[i] = []

			for featureset in data:
				j = self.pred(featureset)
				self.classifications[j].append(featureset)

			prev_centroids = np.copy(self.cluster_centers)
			# print(self.cluster_centers[0])
			# i = 0
			for classification in self.classifications:
				if( not(len(self.classifications[classification]) == 0)):
					self.cluster_centers[classification] = np.average(self.classifications[classification],axis=0)

			# print(self.cluster_centers)
			optimized = True

			for c in range(self.n_clusters):
				original_centroid = prev_centroids[c]
				current_centroid = self.cluster_centers[c]
				if np.linalg.norm(original_centroid-current_centroid) > epsilon:
					# print(np.sum((current_centroid-original_centroid)/original_centroid*100.0))
					optimized = False

			if optimized:
				break

			### Update labels for each point


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

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
	h = [2,5,10]
	fig, axs = plt.subplots(1, 3)
	
	for i in range(3):
		image = plt.imread(f'data/{args.image}.png')
		x = image.reshape(-1, 3)
		kmeans = KMeans(D=3, n_clusters=h[i])
		kmeans.init_clusters(x)
		kmeans.train(x)
		out = kmeans.replace_by_center(x)
		axs[i].imshow(out.reshape(image.shape))
		axs[i].title.set_text(('k = ',h[i]))
		
	plt.show()

