n = int(input())
a = list(map(int,input().split()))
ret = 0
for i in range(n):
    min_i = i
    for j in range(i+1,n):
        if a[j] < a[min_i]:
            min_i = j
    if i!= min_i:
        ret += 1
        a[i],a[min_i]=a[min_i],a[i]
print(" ".join(map(str,a)))
print(ret)

