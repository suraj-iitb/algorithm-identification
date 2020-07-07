n = int(input())
a = list(map(int,input().split()))
c = 0
for i in range(n-1):
    min = a[i]
    ch = i
    for j in range(i+1,n):
        if min > a[j]:
            min = a[j]
            ch = j
    if i != ch:
        a[i], a[ch] = a[ch], a[i]
        c += 1
print(" ".join(map(str,a)))
print(c)
