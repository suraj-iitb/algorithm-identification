_, vs, c = input(), list(map(int, input().split())), 0
for i in range(len(vs)):
    for j in range(len(vs)-1, i, -1):
        if vs[j] < vs[j-1]:
            vs[j], vs[j-1] = vs[j-1], vs[j]
            c += 1
print(' '.join(map(str, vs)))
print(c)
