n = int(input())
a = list(map(int, input().split()))

print(*a)
for i in range(1, n):
    v = a[i]
    while i-1 >= 0 and a[i-1]>v:
        a[i]=a[i-1]
        i -= 1
    a[i] = v
    print (*a)

