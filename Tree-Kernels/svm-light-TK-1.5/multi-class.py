algo = ['linear', 'binary', 'bfs', 'dfs']

pred = {}
for i in range(0, len(algo)):
    j = i + 1
    while j < len(algo):
        print(algo[i], algo[j])
        with open('../Prediction/Searching/'+algo[i]+'_'+algo[j]+'.pred', 'r') as f:
            lines = f.read().split('\n')
            pred[algo[i]+'_'+algo[j]] = lines
        j += 1
print(pred)

with open('../Prediction/Searching/final-ans.pred', 'w') as ans:
    with open('../Data/Searching/AST/algo-r1.test', 'r') as f:
        lines = f.read().split('\n')
        line_no = 0
        for line in lines:
            print(line)
            count = {'linear':0, 'binary':0, 'bfs':0, 'dfs':0}
            for i in range(0, len(algo)):
                j = i + 1
                while j < len(algo):
                    print(algo[i], algo[j])
                    print(pred[algo[i]+'_'+algo[j]][line_no])
                    # if( pred[algo[i]+'_'+algo[j]][line_no] != '' ):
                    if float(pred[algo[i]+'_'+algo[j]][line_no]) >= 0.0:
                        count[algo[i]] += 1
                    else:
                        count[algo[j]] += 1
                    j += 1
            # voting
            voted_algo = max(count, key=count.get)
            ans.write(voted_algo+'\n')
            line_no += 1
