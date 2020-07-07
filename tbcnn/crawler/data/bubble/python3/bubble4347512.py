n = int(input())
l = list(map(int, input().split()))

count = 0
flag = True
while flag:
    flag = False
    for j in range(n-1, 0, -1):
        if l[j] < l[j-1]:
            l[j], l[j-1] = l[j-1], l[j]
            count += 1
            flag = True

print(' '.join(map(str, l)))
print(count)

