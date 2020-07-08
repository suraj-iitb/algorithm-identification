import pickle
import json

with open('/home/suraj/Documents/MTP/tbcnn/vectorizer/data/vectors.pkl', 'rb') as p:
    with open('/home/suraj/Documents/MTP/tbcnn/vectorizer/data/vectors.txt', 'w') as f:
        data_source = pickle.load(p)
        vecs = data_source[0]
        labels = data_source[1]
        labels = list(labels.keys())
        for i in range(len(vecs)):
            f.write(labels[i] + '\n' + str(vecs[i]) + '\n\n')

