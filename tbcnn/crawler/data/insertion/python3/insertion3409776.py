n = int(input())
r = list(map(int,input().split()))
for i in range(n):
    value = r[i]
    while i >= 1 and r[i-1] > value:
        r[i] = r[i-1]
        i -= 1
    r[i] = value
    print(*r)
