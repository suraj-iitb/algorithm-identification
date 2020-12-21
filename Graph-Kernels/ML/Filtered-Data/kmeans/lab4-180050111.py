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
		z = x.reshape((1,x.shape[0]))
		z = (self.cluster_centers - z)**2
		return np.argmin(np.sum(z, axis=1))

		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			def fn(z):
				z = z.reshape((1,z.shape[0]))
				z = (self.cluster_centers - z)**2
				return np.argmin(np.sum(z, axis=1))

			### Update labels for each point
			labels = np.apply_along_axis(fn, 1, data)


			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			cnt = np.zeros(self.n_clusters)
			sm = np.zeros(self.cluster_centers.shape)
			for i in range(len(labels)):
				lab = labels[i]
				cnt[lab]+=1
				sm[lab] += data[i]
			new_cluster_centers = np.copy(self.cluster_centers)
			for i in range(self.n_clusters):
				if cnt[i]>0:
					new_cluster_centers[i] = sm[i] / cnt[i]


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			df = self.cluster_centers - new_cluster_centers
			if np.sum(np.sum(df**2, axis=1)) < epsilon:
				break

			self.cluster_centers = new_cluster_centers
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

	# for imgs in ['1','2','3']:
	# 	image = plt.imread(f'data/{imgs}.png')
	# 	x = image.reshape(-1, 3)
	# 	ax = [0]*20
	# 	fig, (ax[2], ax[5], ax[10]) = plt.subplots(1, 3)
	# 	for k in [2,5,10]:
	# 		kmeans = KMeans(D=3, n_clusters=k)
	# 		kmeans.init_clusters(x)
	# 		kmeans.train(x)
	# 		out = kmeans.replace_by_center(x)
	# 		ax[k].imshow(out.reshape(image.shape))
	# 		ax[k].set_title('k = %s' % k)
	# 	plt.show()