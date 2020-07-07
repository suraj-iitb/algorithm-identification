n = int(input())
a = [int(x) for x in input().split()]

c = 0

for i in range(n - 1):
    minj = i
    for j in range(i + 1, n):
        if a[j] < a[minj]:
            minj = j
    if minj != i:
        tmp = a[i]
        a[i] = a[minj]
        a[minj] = tmp
        c += 1

print(" ".join([str(x) for x in a]))
print(c)
