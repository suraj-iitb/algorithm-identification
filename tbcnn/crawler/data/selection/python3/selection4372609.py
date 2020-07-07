n = int(input())
a = list(map(int,input().split()))
cnt = 0
for i in range(n-1):
    min = i+1
    for j in range(i+1,n):
        if a[min] > a[j]:
            min = j
    if a[i] > a[min]:
        a[i],a[min] = a[min],a[i]
        cnt += 1
for i in range(n):
    if i != n-1:
        print(a[i], end=' ')
    else:
        print(a[i])
print(cnt)
