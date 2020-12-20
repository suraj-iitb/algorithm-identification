import os

with open('../Results/all/100/100_svm.csv', 'r') as s:
    with open('../Results/all/100/100_svm_feature_vector.csv', 'w') as ans:
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
            temp = []

            for i in range(0, len(sim), 2):
                if sim[i].startswith('bubble'):
                    b.append(sim[i+1])
                elif sim[i].startswith('insertion'):
                    ins.append(sim[i+1])
                elif sim[i].startswith('selection'):
                    s.append(sim[i+1])
                elif sim[i].startswith('counting'):
                    c.append(sim[i+1])
                elif sim[i].startswith('merge'):
                    m.append(sim[i+1])
                elif sim[i].startswith('quick'):
                    q.append(sim[i+1])

            temp.extend(b)
            temp.extend(ins)
            temp.extend(s)
            temp.extend(c)
            temp.extend(m)
            temp.extend(q)
            # b.sort(reverse=True)
            # ins.sort(reverse=True)
            # s.sort(reverse=True)
            # c.sort(reverse=True)
            # m.sort(reverse=True)
            # q.sort(reverse=True)
            # print(b, ins, s, c, m, q)

            ans.write(line[0].strip())
            # for algo in [b, ins, s, c, m, q]:
            #     count = 0
            #     for i in algo:
            #         ans.write(','+str(i))
            #         count += 1
            #         if(count == 10):
            #             break
            #     for i in range(count, 10):
            #         ans.write(',0')
            ans.write(','.join(temp))
            ans.write('\n')

            
