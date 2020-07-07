n = int(input())
a = list(map(int, input().split()))
b = []
for i in range(n):
    k = a[i]
    j = i - 1
    while j >= 0 and a[j] > k:
        a[j+1] = a[j]
        a[j]=k
        j-=1
    print(*a)

