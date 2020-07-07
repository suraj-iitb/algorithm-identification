n = int(input())
ls = list(map(int, input().split()))

count = 0
flag = 1
while flag:
    flag = 0
    for i in range(len(ls)-1, 0, -1):
        if ls[i] < ls[i-1]:
            ls[i], ls[i-1] = ls[i-1], ls[i]
            count += 1
            flag = 1
print(' '.join(map(str, ls)))
print(count)
