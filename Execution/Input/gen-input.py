n_list = [10, 100, 1000]

# Range of input
for n in range(10000, 1000001, 10000):
    n_list.append(n)

# Generate input
for n in n_list:
    with open('input-'+str(n), 'w') as f:
        f.write(str(n))
        for i in range (n, 0, -1):
            f.write(' '+str(i))
