num = int(input())
x = list(map(int, input().split()))
n = 0

flag = 1
while flag:
    flag = 0
    for j in range(1, num):
        if x[j] < x[j-1]:
            x[j], x[j-1] = x[j-1], x[j]
            flag = 1
            n += 1
print(' '.join([str(s) for s in x]))
print(n)
