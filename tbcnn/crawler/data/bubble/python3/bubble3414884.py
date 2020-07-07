n = int(input())
x = list(map(int, input().split())) 
flag = 1
i = 0
v = 0
j = n-1
cont = 0
for i in range(n):
    for k in range(n-1, i, -1):
        if x[k] < x[k-1]:
            v = x[k-1]
            x[k-1] = x[k]
            x[k] = v
            cont = 1 + cont
print(*x)
print(cont)
