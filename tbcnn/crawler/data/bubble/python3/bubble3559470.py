n = int(input())
a = list(map(int, input().split()))

c = 0
flag = 1
while flag:
    flag=0
    for j in reversed(range(1, n)):
        if a[j] < a[j-1]:
            b = a[j]
            a[j] = a[j-1]
            a[j-1] = b
            flag = 1
            c += 1
print(*a)
print(c)
