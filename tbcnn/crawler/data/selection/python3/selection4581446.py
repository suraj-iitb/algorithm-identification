n = int(input())
x = list(map(int,input().split()))
c = 0

for i in range(n):
    min = i
    for j in range(i+1,n):
        if x[min] > x[j]:
            min = j
    if i != min:       
        x[i],x[min] = x[min],x[i]
        c += 1

print(*x)
print(c)
