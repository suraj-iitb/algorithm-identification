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
        self.cluster_centers = data[np.random.choice(data.shape[0], self.n_clusters, replace = False)]
		
        ### END TODO

    def pred(self, x):
        ### TODO: Given a sample x, return id of closest cluster center
        return np.argmin(np.linalg.norm(x-self.cluster_centers, axis=1))
        ### END TODO

    def train(self, data, max_iter=10000, epsilon=1e-4):
        for it in range(max_iter):
            #print(it)
            ### TODO
            ### Declare and initialize required variables
            n = self.n_clusters
            clust = np.copy(self.cluster_centers)
            
            def mul(X):
                return np.sum(X**2)
            mul_vec = np.vectorize(mul)
            # NOTE THAT YOU CANNOT USE FOR LOOPS HERE 
            X = data
            Y = clust
            #X2 = mul_vec(data)
            #Y2 = mul_vec(self.cluster_centers)
            X2 = np.sum(X**2,axis=1)
            Y2 = np.sum(Y**2,axis=1)
            X2Y = 2*X@Y.T
            X2 = np.repeat(X2,Y.shape[0])
            Y2 = np.repeat(Y2,X.shape[0])
            X2 = X2.reshape(X.shape[0],Y.shape[0])
            Y2 = Y2.reshape(Y.shape[0],X.shape[0])
            Y2 = Y2.T
            e = X2+Y2-X2Y
            
            
            

            ### Update labels for each point
            labels = np.argmin(e,axis=1)

            ### Update cluster centers
            ### Note: If some cluster is empty, do not update the cluster center
            for i in range(n):
                if np.sum(labels==i):
                    self.cluster_centers[i] = np.mean(data[labels==i],axis=0)

            ### Check for convergence
            ### Stop if distance between each of the old and new cluster centers is less than epsilon
            if np.sum((self.cluster_centers-clust)**2) < epsilon**2:
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

