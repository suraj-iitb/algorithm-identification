N = int(input())
a = list(map(int, input().split()))

count = 0

for i in range(N):
    minj = i
    for j in range(i+1, N):
        if a[minj]>a[j]:
            minj = j
    if a[i]!=a[minj]:
        a[i], a[minj] = a[minj], a[i]
        count += 1
print(' '.join(map(str, a)))
print(count)

