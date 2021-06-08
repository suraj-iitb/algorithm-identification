from sklearn import metrics

algo = ['linear', 'binary', 'bfs', 'dfs']

y_pred = []
y_true = []

with open('../Prediction/Searching/final-ans.pred', 'r') as f:
    for i in f:
        if i != '':
            i = i.strip()
            y_pred.append(i)

with open('../Data/Searching/AST/algo-r1.test', 'r') as g:
    for i in g:
        if i != '':
            i = i.strip().split(' ')
            y_true.append(algo[int(i[0])])

print(len(y_true))
print(len(y_pred))      

with open('../Prediction/Searching/metrics-r1.txt', 'w') as op:
    # Print the confusion matrix
    op.write(str(metrics.confusion_matrix(y_true, y_pred)))

    # Print the precision and recall, among other metrics
    op.write(str(metrics.classification_report(y_true, y_pred, digits=2)))