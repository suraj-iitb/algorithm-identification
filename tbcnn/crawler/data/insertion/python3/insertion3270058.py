n = int(input())
a = list(map(int, input().split()))
for i in range(0, n-1):
    print(a[i], end=" ")
print(a[n-1])
for i in range(1, n):
    v = a[i]
    j = i-1
    while j>=0 and a[j]>v:
        a[j+1] = a[j]
        j-=1
    a[j+1] = v
    for i in range(0, n-1):
        print(a[i], end=" ")
    print(a[n-1])