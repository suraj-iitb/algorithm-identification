n = int(input())
x = list(map(int,input().split()))
print (*x)
for i in range(1,n):
    v = x[i]
    j = i - 1
    while j >= 0:
        if x[j] > v:
            x[j + 1] = x[j]
            x[j] = v
        j += -1
    print (*x)
