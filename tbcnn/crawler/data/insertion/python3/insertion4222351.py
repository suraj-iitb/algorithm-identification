n = int(input())
a = list(map(int,input().split()))
print(*a)
for i in range(1,n):
    for j in range(i):
        p = i-j
        if a[p] < a[p-1]:
             a[p], a[p-1] = a[p-1], a[p]
    print (*a)
