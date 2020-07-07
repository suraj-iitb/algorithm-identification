n = int(input())
x = list(map(int,input().split()))
for i in range(n):
    temp = x[i]
    j = i - 1
    while j>= 0 and x[j] > temp:
        x[j+1] = x[j]
        j -= 1
    x[j+1] = temp
    print(*x)

