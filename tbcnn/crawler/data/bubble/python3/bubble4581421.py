n = int(input())
x = list(map(int,input().split()))
c = 0

change = 1
for i in range(n):
    if not change:
        break
    change = 0
    for j in range(n-i-1):
        if x[j] > x[j+1]:
            x[j],x[j+1] = x[j+1],x[j]
            change = 1
            c += 1

print(*x)
print(c)
