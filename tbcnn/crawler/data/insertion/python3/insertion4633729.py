n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    b = sorted(a[:i+1])
    b.extend(a[i+1:])
    print(' '.join([str(i) for i in b]))
