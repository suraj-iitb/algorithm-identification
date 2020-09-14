from sklearn import metrics
import os

d = {'b': 'bubble', 'i': 'insertion', 's': 'selection', 'q':'quick', 'm': 'merge', 'c': 'counting', 'n':'none'}

y_true = []
y_pred = []

path = 'Results/all/100/'
for file in os.listdir(path):
    if 'labels' in file:
        print(file)
        with open(path+file[:-4]+'_metrics.csv', 'w') as op:
            with open(path+file) as h:
                for line in h:
                    line = line.strip().split(',')
                    y_true.append(d[line[0][0]])
                    y_pred.append(d[line[1][0]])  

                # print(y_true)
                # print(y_pred)      

                # Print the confusion matrix
                op.write(str(metrics.confusion_matrix(y_true, y_pred)))

                # Print the precision and recall, among other metrics
                op.write(str(metrics.classification_report(y_true, y_pred, digits=2)))

                y_true.clear()
                y_pred.clear()