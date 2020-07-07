num = int(input())
data = list(map(int, input().split()))
for i in range(num):
    for j in range(i, 0, -1):
        if data[j] < data[j-1]:
            data[j-1], data[j] = data[j], data[j-1]
    print(' '.join(map(str, data)))
