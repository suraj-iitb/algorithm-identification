n = int(input())
a = list(map(int, input().split()))
t = 0

flag = 1
while(flag):
    flag = 0
    for i in range(n - 1, 0, -1):
        if a[i] < a[i - 1]:
            a[i], a[i - 1] = a[i - 1], a[i]
            flag = 1
            t += 1

print(' '.join(map(str, a)))
print(t)
