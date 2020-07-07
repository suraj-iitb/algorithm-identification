n = int(input())
x = list(map(int,input().split()))

count = 0

for i in range(n - 1):
    minx = i
    for j in range(i + 1,n):
        if x[j] < x[minx]:
            minx = j
        
    if not i == minx:
        x[i],x[minx]=x[minx],x[i]
        count += 1

x = list(map(str,x))
print (" ".join(x))
print(count)
