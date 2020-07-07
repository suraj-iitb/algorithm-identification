cnt = 0
input()
num = [int(n) for n in input().split()]
for i in range(len(num) - 1):
    for j in range(len(num) - 1, i, -1):
        if num[j] < num[j - 1]:
            num[j], num[j - 1] = num[j - 1], num[j]
            cnt += 1
print(' '.join([str(n) for n in num]))
print(cnt)
