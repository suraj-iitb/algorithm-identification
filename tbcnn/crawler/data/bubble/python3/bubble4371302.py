n = int(input())
a = list(map(int,input().split()))
cnt = 0
i = 0
while i < n-1:
    for j in range(n-1,i,-1):
        if a[j] < a[j-1]:
            a[j-1],a[j] = a[j],a[j-1]
            cnt += 1
    i += 1
for i in range(n):
    if i != n-1:
        print(a[i], end=' ')
    else:
        print(a[i])
print(cnt)
