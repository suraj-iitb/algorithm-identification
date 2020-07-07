n = int(input())
*v, = map(int, input().split())
v = v[:n]

for i in range(n):
    k = v[i]
    j = i-1
    while j >= 0 and v[j] > k:
        v[j+1] = v[j]
        j -= 1
    v[j+1] = k
    print(" ".join([str(_v) for _v in v]))

