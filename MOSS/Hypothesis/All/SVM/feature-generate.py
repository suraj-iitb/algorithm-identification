import os

with open('../Results/all/75/75_svm.csv', 'r') as s:
    with open('../Results/all/75/75_svm_feature_vector.csv', 'w') as ans:
        for line in s:
            line = line.strip().split(',')
            sim = line[1:]
            print(sim)

            # vector count
            b = []
            ins = []
            s = []
            c = []
            m = []
            q = []

            for i in range(0, len(sim), 2):
                if sim[i].startswith('bubble'):
                    b.append(int(sim[i+1]))
                elif sim[i].startswith('insertion'):
                    ins.append(int(sim[i+1]))
                elif sim[i].startswith('selection'):
                    s.append(int(sim[i+1]))
                elif sim[i].startswith('counting'):
                    c.append(int(sim[i+1]))
                elif sim[i].startswith('merge'):
                    m.append(int(sim[i+1]))
                elif sim[i].startswith('quick'):
                    q.append(int(sim[i+1]))

            b.sort(reverse=True)
            ins.sort(reverse=True)
            s.sort(reverse=True)
            c.sort(reverse=True)
            m.sort(reverse=True)
            q.sort(reverse=True)
            print(b, ins, s, c, m, q)

            ans.write(line[0].strip())
            for algo in [b, ins, s, c, m, q]:
                count = 0
                for i in algo:
                    ans.write(','+str(i))
                    count += 1
                    if(count == 10):
                        break
                for i in range(count, 10):
                    ans.write(',0')
            ans.write('\n')

            
