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
		rng=np.random.default_rng()
		self.cluster_centers=rng.choice(data,self.n_clusters,replace=False)
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		sam=x.reshape((1,self.cluster_centers.shape[1]))

		return np.argmin(np.linalg.norm(self.cluster_centers-sam,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			new_centers=self.cluster_centers.copy()


			### Update labels for each point
			dist=np.linalg.norm(self.cluster_centers-data.reshape((data.shape[0],1,data.shape[1])),axis=2)
			# print(dist)
			labels=np.argmin(dist,axis=1)#.reshape((data.shape[0],1))
			# print(labels)

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			# print(data.shape)
			# print(labels==0)
			for i in range(self.n_clusters):
				if(not np.all(np.invert(labels==i))):
					new_centers[i]=np.average(data[labels==i],axis=0)
				# else:
				# 	new_centers[i]=self.cluster_centers[i].copy()


			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			diff=np.linalg.norm(new_centers-self.cluster_centers,axis=1)
			if np.all(diff<epsilon):
			# if(np.allclose(new_centers,self.cluster_centers,atol=epsilon,rtol=0)):
				# self.cluster_centers=new_centers.copy()
				break
			else:
				# print("\niteration: ",it)
				# print("error=",diff)
				# print(new_centers)
				# print(diff<epsilon)
				self.cluster_centers=new_centers.copy()
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

