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
		self.cluster_centers=data[np.random.randint(data.shape[0],size=self.n_clusters)]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		idx=0
		min=np.linalg.norm(x-self.cluster_centers[0])
		for i in range(1,self.n_clusters):
			dist=np.linalg.norm(x-self.cluster_centers[i])
			if min>dist:
				min=dist
				idx=i

		return idx
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		num=0
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# print(it)
			num=it
			P=np.zeros((self.n_clusters,data.shape[0]))
			P[:,0]=np.ones(self.n_clusters)
			### Update labels for each point
			for i in range(data.shape[0]):
				P[:,i]=np.zeros(self.n_clusters)
				P[self.pred(data[i]),i]=1

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			prev_centers=np.copy(self.cluster_centers)
			for i in range(self.n_clusters):
				deno=np.sum(P[i,:])
				if deno==0:
					continue
				else:
					nume=P[i,:] @ data
					self.cluster_centers[i]=nume/deno

			# print(self.cluster_centers)
			# print(prev_centers)
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			state=1
			for i in range(self.n_clusters):
				if np.linalg.norm(self.cluster_centers[i]-prev_centers[i])>epsilon:
					state=0
					break

			if state==1:
				break

			### END TODO
		return num

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

