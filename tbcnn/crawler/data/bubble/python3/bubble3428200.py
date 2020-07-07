n = int(input())
*v, = map(int, input().split())

c = 0
for i in range(n):
    for j in range(n-1, i, -1):
        if v[j] < v[j-1]:
            v[j], v[j-1] = v[j-1], v[j]
            c += 1

print(" ".join([str(_v) for _v in v]))
print(c)

