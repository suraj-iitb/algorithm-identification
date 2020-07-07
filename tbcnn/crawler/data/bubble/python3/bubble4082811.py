n = int(input())
*a, = map(int, input().split())

ans = 0
j = 0
flag = True
while flag:
    flag = False
    for i in range(n - 1, j, -1):
        if a[i] < a[i - 1]:
            a[i], a[i - 1] = a[i - 1], a[i]
            flag = True
            ans += 1
    j += 1
else:
    print(*a)
    print(ans)

