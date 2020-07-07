n = int(input())
a = [int(x) for x in input().split()]
c = 0
for x in range(n):
    for i in range(n-1, x, -1):
        if a[i] < a[i-1]:
            a[i], a[i-1] = a[i-1], a[i]
            c += 1
print(*a)
print(c)
