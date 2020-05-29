# steps = 1
# n_list = [10,100,1000, 5000,10000,20000,30000,40000,50000,60000,70000, 80000,90000, 100000]
nlist = [10,100]
for n in range(1000, 100000, 1000):
    n_list.append(n)

for n in n_list:
    with open('input-'+str(n), 'w') as f:
        f.write(str(n))
        for i in range (n, 0, -1):
            f.write(' '+str(i))
