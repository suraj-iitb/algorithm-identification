n = int(input())
a = list(map(int, input().split()))
flag = 1
c = 0
while flag:
    flag = 0
    for k in range(1, n):
        if a[k]<a[k-1]:
            a[k-1], a[k] = a[k], a[k-1]
            flag = 1
            c += 1
print(*a)
print(c)
