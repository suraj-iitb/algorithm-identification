n = int(input())
x = input().split()
y=[]
for i in range(n):
    y += [int(x[i])]
for i in range(n-1):
    print(y[i],end=' ')
print(y[n-1])

for i in range(1,n):
    v = y[i]
    j = i-1
    while j >= 0 and y[j] > v:
        y[j+1] = y[j]
        j -= 1
    y[j+1] = v
    for j in range(n-1):
        print(y[j],end=' ')
    print(y[n-1])

