n = int(input())
k = [int(i) for i in input().split()]
m = 0

for i in range(n):
    minj = i
    for j in range(i,n):
        if k[j] < k[minj]:
            minj = j
    x = k[i]
    k[i] = k[minj]
    k[minj]=x
    if k[i] != k[minj]:
        m += 1


print(' '.join(map(str, k)))
print(m)
