n = int(input())
a = list(map(int, input().split()))
count = 0

flag = 1
while flag:
    flag = 0
    for j in range(1, n):
        num = a[j]
        if a[j] < a[j-1]:
            a[j] = a[j-1]
            a[j-1] = num
            count += 1
            flag = 1

print(*a, sep=' ')
print(count)
