n = int(input())
a = list(map(int,input().split()))
c = 0
for _ in range(n):
    for i in range(n-1,0,-1):
        if a[i] < a[i-1]:
            a[i],a[i-1] = a[i-1],a[i]
            c += 1
print(" ".join(map(str,a)))
print(c)
