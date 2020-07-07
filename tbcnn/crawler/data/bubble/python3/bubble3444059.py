n = int(input())
a = [int(i) for i in input().split()]
flag = True
cnt = 0
while flag:
    flag = False
    for i in range(1,n)[::-1]:
        if a[i] < a[i-1]:
            a[i], a[i-1] = a[i-1], a[i]
            cnt += 1
            flag = True
print(' '.join([str(i) for i in a]))
print(cnt)

