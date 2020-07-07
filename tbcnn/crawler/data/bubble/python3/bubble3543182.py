n = int(input())
data = list(map(int, input().split()))
counter = 0
for i in range(n-1, 0, -1):
    for j in range(i):
        if data[j] > data[j+1]:
            tmp = data[j]
            data[j] = data[j+1]
            data[j+1] = tmp
            counter += 1
print(*data)
print(counter)

