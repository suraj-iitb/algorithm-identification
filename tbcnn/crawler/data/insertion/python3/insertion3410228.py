n = int(input())
x = list(map(int, input().split())) 
for i in range(n):
    v = x[i]
    j = i-1
    while j >=0 and x[j]>v:
        x[j+1] = x[j]
        j = j-1
    x[j+1] = v
    print(*x)
