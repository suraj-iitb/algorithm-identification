n = int(input())
a = []
a = input().split()
a = list(map(int,a))
num = 0
i = 0
flag = 1
while flag == 1:
    flag = 0
    for j in range(n-1, i, -1):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            flag = 1
            num = num + 1
    i = i + 1
print(*a)
print(num)


