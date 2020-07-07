n = int(input())
l = list(map(int, input().split(" ")))
f = 0
for _ in l:
    for j in range(n - 1, 0, -1):
        if l[j] < l[j - 1]:
            l[j], l[j - 1] = l[j - 1], l[j]
            f += 1
print(*l)
print(f)
