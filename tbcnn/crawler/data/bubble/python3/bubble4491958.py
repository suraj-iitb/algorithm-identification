n = int(input())
l = list(map(int, input().split()))

flag = 1
e = 0
while flag:
    flag = 0
    for j in range(n-1, 0, -1):
        if l[j] < l[j-1]:
            v = l[j]
            l[j] = l[j-1]
            l[j-1] = v
            flag = 1
            e += 1
print(*l)
print(e)
