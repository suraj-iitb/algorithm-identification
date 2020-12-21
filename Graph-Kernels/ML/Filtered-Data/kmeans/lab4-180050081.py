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

		self.cluster_centers = data[:self.n_clusters]

		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center

		temp = self.cluster_centers - x
		temp = np.square(temp)
		temp_sum = np.sum(temp, axis = 1)

		return np.argmin(temp_sum)

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables

			num_points = data.shape[0]
			P = np.zeros((self.n_clusters, num_points))

			### Update labels for each point

			for i in range(num_points):
				index = self.pred(data[i])
				P[index,i] = 1

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center

			old = self.cluster_centers.copy()

			for i in range(self.n_clusters):
				den = np.sum(P[i])
				if den > 0:
					self.cluster_centers[i] = (P[i] @ data) / den

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon

			temp = abs(old - self.cluster_centers)
			temp = np.square(temp)
			temp_sum = np.sum(temp, axis = 1)
			temp_sum = np.sqrt(temp_sum)

			if np.max(temp_sum) < epsilon:
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

	# image_nums = [1,2,3]
	# k_choices = [2,5,10]
	# for i in image_nums:
	# 	fig,ax = plt.subplots(nrows=1,ncols=3, figsize=(9,3))
	# 	inner_index = 0
	# 	for k in k_choices:

	# 		image = plt.imread(f'data/{str(i)}.png')
	# 		x = image.reshape(-1, 3)
	# 		kmeans = KMeans(D=3, n_clusters=k)
	# 		kmeans.init_clusters(x)
	# 		kmeans.train(x)
	# 		out = kmeans.replace_by_center(x)

	# 		ax[inner_index].imshow(out.reshape(image.shape))
	# 		ax[inner_index].set_title(f'image_{str(i)} with {str(k)} clusters')

	# 		inner_index += 1

	# 	plt.tight_layout()
	# 	plt.show()
