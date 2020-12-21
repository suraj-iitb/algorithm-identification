import argparse
import numpy as np
import matplotlib.pyplot as plt

# np.random.seed(1110)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters
		self.cluster_centers = np.zeros((n_clusters, D))

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data
		# for i in range(self.n_clusters):
		# 	self.cluster_centers[i] = data[np.random.randint(0,data.shape[0]-1)]
		# self.cluster_centers = np.random.sample(data,self.n_clusters)
		# centroids = data.copy()
		# np.random.shuffle(centroids)

		random_indices = np.random.choice(data.shape[0], size=self.n_clusters, replace=False)
		self.cluster_centers = data[random_indices,:]
		# self.cluster_centers = centroids[:self.n_clusters,:]
		# print(self.cluster_centers)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		ans = 0
		mindist = np.linalg.norm(x - self.cluster_centers[0,:])
		for j in range(self.n_clusters):
			dist = np.linalg.norm(x - self.cluster_centers[j,:])
			if(dist<mindist):
				ans = j
		return ans
				
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-5):
		for it in range(max_iter):
			### TODO
			# if(it%10==0):
			# print(it)
			### Declare and initialize required variables
			labels = np.zeros(data.shape[0])
			sum = np.zeros((self.n_clusters,self.cluster_centers.shape[1]))
			count = np.zeros(self.n_clusters)
			newclustercenters =  np.zeros((self.n_clusters,self.cluster_centers.shape[1]))


			### Update labels for each point

			for i in range(data.shape[0]):
				mindist = np.linalg.norm(data[i,:] - self.cluster_centers[0,:])
				for j in range(self.n_clusters):
					dist = np.linalg.norm(data[i,:] - self.cluster_centers[j,:])
					if(dist<mindist):
						labels[i] = j
			



			### Update cluster centers
			for i in range(data.shape[0]):
				l = labels[i]
				# print(self.n_clusters)
				# print(sum[4,:])
				sum[int(l)] = sum[int(l)] + data[i]
				count[int(l)] = count[int(l)] + 1
			
			for i in range(self.n_clusters):
				if(count[i]>0):
					newclustercenters[i] = sum[i]/count[i]
				else:
					newclustercenters[i] = self.cluster_centers[i]



			### Note: If some cluster is empty, do not update the cluster center


			### Check for convergence
			enditer = True
			for i in range(self.n_clusters):
				n = np.linalg.norm(self.cluster_centers[i]-newclustercenters[i])
				if(n>epsilon):
					enditer = False
					break
			
			if(enditer):
				break
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			self.cluster_centers = newclustercenters
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

