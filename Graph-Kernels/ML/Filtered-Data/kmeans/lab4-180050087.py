import argparse
import numpy as np
import matplotlib.pyplot as plt
# import sys
# np.set_printoptions(threshold=sys.maxsize)
np.random.seed(5927)

class KMeans():
	def __init__(self, D, n_clusters):
		self.n_clusters = n_clusters
		self.cluster_centers = np.zeros((n_clusters, D))

	def init_clusters(self, data):
		### TODO
		### Initialize cluster_centers using n_clusters points sampled from data
		ind=np.random.choice(data.shape[0],self.n_clusters,replace=False)
		self.cluster_centers=data[ind,:]		
		### END TODO

	def pred(self, x):
		### TODO: Given a sample x, return id of closest cluster center
		# print(np.argmin(np.linalg.norm(self.cluster_centers-x)**2))
		return np.argmin(np.linalg.norm(self.cluster_centers-x,axis=1))
		### END TODO

	def train(self, data, max_iter=10000, epsilon=1e-4):
		for it in range(max_iter):
			### TODO
			### Declare and initialize required variables
			# print(it)
			P=np.zeros((data.shape[0],self.n_clusters))
			c=np.copy(self.cluster_centers)
			# print(c)
			# print(data[:5,:])
			X1=np.sum(np.multiply(data,data),axis=1,keepdims=True)
			Y1=np.sum(np.multiply(c,c),axis=1,keepdims=True)
			N=np.argmin(X1-2*(data @ c.T) + Y1.T,axis=1)
			P[np.arange(data.shape[0]),N]=1
			# print(P.T)
			### Update labels for each point

			### Update cluster centers
			### Note: If some cluster is empty, do not update the cluster center
			Pused=P.T
			ele=np.sum(P.T,axis=1,keepdims=True)
			ind = np.where(ele!=0)[0]
			self.cluster_centers[ind,:]=(Pused[ind,:] @ data)/np.sum(Pused[ind,:],axis=1,keepdims=True)
			# print(self.cluster_centers)
			### Check for convergence
			### Stop if distance between each of the old and new cluster centers is less than epsilon
			# print(abs(c-c1[ind]))
			normdiff=np.linalg.norm(c-self.cluster_centers,axis=1)
			if np.max(normdiff) < epsilon:
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
	plt.title('image='+str(args.image)+' k='+str(args.k))
	plt.savefig('image='+str(args.image)+' k='+str(args.k)+'.png')

