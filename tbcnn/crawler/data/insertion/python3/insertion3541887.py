n = int(input())
data = list(map(int, input().split()))
print(*data)
for i in range(1, n):
    v = data[i]
    j = i-1
    while j>=0 and data[j] > v:
        data[j+1] = data[j]
        j-=1
    data[j+1] = v
    print(*data)

