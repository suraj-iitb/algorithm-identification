n = int(input())
a = list(map(int, input().split()))

k = 0

for i in range(0, n):
    minj = i
    for j in range(i, n):
        if a[j] < a[minj]:
            minj = j
    if i != minj:
        k += 1
        t = a[i]
        a[i] = a[minj]
        a[minj] = t
for i in range(0, n - 1):
    print(a[i], end=' ')
print(a[n - 1])
print(k)
