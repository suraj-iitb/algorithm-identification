n = int(input())
a = [int(i) for i in input().split()]
c = 0
for i in range(n):
    minj = i
    for j in range(i,n):
        if a[j] < a[minj]:
            minj = j
    if a[i] != a[minj]:
        c += 1
    a[i],a[minj]=a[minj],a[i]
print(' '.join(map(str,a)))
print(c)
