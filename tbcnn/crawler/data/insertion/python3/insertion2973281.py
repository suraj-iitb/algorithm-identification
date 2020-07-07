n = int(input())
nlist = list(map(int, input().split()))
for i in range(n):
    j = i-1
    v = nlist[i]
    while (j >= 0 and nlist[j] > v):
        nlist[j+1] = nlist[j]
        j -= 1
    nlist[j+1] = v
    for k in range(n):
        if (k == n-1):
            print(nlist[k], end = '')
        else:
            print(nlist[k], end = ' ')
    print()
