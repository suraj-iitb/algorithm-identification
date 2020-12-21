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
		self.cluster_centers = data[:self.n_clusters,:]
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		X1 = (self.cluster_centers-x)*(self.cluster_centers-x)
		X2=np.sum(X1, axis = 1)
		K=np.argmin(X2)
		return K
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			#print("kjqdc")
			a=self.cluster_centers
			b=self.n_clusters
			#print("kjqdc")
			total=np.zeros(b)
			#print("kjqdc")
			centers=np.zeros_like(a)
			#print("kjqdc")

			### Update labels for each point
			#print("hajbavbbfv")
			n=len(data)
			#print("kjqdc")
			#print(n)
			for i in range(n):
				#print("kjqdc")
				#print(self.pred(data[i]))
				centers[self.pred(data[i])]=centers[self.pred(data[i])]+data[i,:]
				#print("kjqdc")
				total[self.pred(data[i])]+=1

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			#print("aLJHFBWELJ")
			for i in range(b):
				##we need to check whether cluster is empty or not
				if total[i]==0: ###it is zero
					centers[i]=self.cluster_centers[i,:]
				else:
					centers[i]=centers[i]/total[i]

			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			#print("abvqwlj")
			X1=(self.cluster_centers-centers)*(self.cluster_centers-centers)
			X2=np.sqrt(np.sum(X1,axis=1))
			o=len(X2)
			self.cluster_centers= centers
			w=0
			for j in range(o):
				if X2[i]>=epsilon:
					w=1
					break
				else:
					w=0
			if w==1:
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
	parser.add_argument('--image', default='3', choices=['1', '2', '3'])
	parser.add_argument('--k', default=10, type=int)

	args = parser.parse_args()

	image = plt.imread(f'data/{args.image}.png')
	x = image.reshape(-1, 3)
	kmeans = KMeans(D=3, n_clusters=args.k)
	kmeans.init_clusters(x)
	kmeans.train(x)
	out = kmeans.replace_by_center(x)
	plt.imshow(out.reshape(image.shape))
	plt.show()

