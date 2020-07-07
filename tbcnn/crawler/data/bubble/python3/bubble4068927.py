n = int(input())
a = list(map(int, input().split()))
count = 0

flag = True
while flag:
    flag = False
    for j in range(n-1, 0, -1):
        if a[j] < a[j-1]:
            x = a[j]
            a[j] = a[j-1]
            a[j-1] = x
            flag = True
            count = count + 1

print(*a)
print(count)
