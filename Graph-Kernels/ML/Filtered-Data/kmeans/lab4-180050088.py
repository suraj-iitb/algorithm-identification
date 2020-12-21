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
        idx = np.random.choice(data.shape[0], size = self.n_clusters, replace = False)
        self.cluster_centers = data[idx, :]
        ### END TODO

    def pred(self, x):
        ### TODO: Given a sample x, return id of closest cluster center
        dist = np.linalg.norm(self.cluster_centers - x, axis = -1)
        return np.where(dist == np.amin(dist))
        ### END TODO

    def train(self, data, max_iter=10000, epsilon=1e-4):
        for it in range(max_iter):
            ### TODO
            ### Declare and initialize required variables
            idx = np.zeros((data.shape[0], 1))
            ### Update labels for each point
            for i in range(idx.shape[0]):
                val = self.pred(data[i])
                idx[i] = val[0][0]
                
            idx = np.reshape(idx, data.shape[0]).astype('int')

            ### Update cluster centers
            ### Note: If some cluster is empty, do not update the cluster center
            new_cluster_centers = np.zeros(self.cluster_centers.shape)
            freq = np.zeros(self.n_clusters)

            for i in range(idx.shape[0]):
                new_cluster_centers[idx[i]] = new_cluster_centers[idx[i]] + data[i]
                freq[idx[i]] = freq[idx[i]] + 1

            for i in range(freq.shape[0]):
                if freq[i] != 0:
                    new_cluster_centers[i] = new_cluster_centers[i] / freq[i]
                else:
                    new_cluster_centers[i] = self.cluster_centers[i].copy()

            ### Check for convergence
            ### Stop if distance between each of the old and new cluster centers is less than epsilon
            norm1 = new_cluster_centers - self.cluster_centers
            if np.all(np.linalg.norm(norm1, axis = 1) < epsilon):
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

