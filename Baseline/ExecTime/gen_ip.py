steps = 1
n_list = []

for _ in range(1, 9):
    steps = steps * 10
    n_list.append(steps)

for n in n_list:
    with open('input-'+str(n), 'w') as f:
        f.write(str(n))
        for i in range (n, 0, -1):
            f.write(' '+str(i))