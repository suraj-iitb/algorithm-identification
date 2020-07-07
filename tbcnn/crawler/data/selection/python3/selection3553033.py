num = int(input())
x = list(map(int, input().split()))
n = 0
for i in range(num):
    min_j = i
    for j in range(i, num):
        if x[min_j] > x[j]:
            min_j = j
    if min_j != i:
        x[i], x[min_j] = x[min_j], x[i]
        n += 1
print(' '.join([str(s) for s in x]))
print(n)
