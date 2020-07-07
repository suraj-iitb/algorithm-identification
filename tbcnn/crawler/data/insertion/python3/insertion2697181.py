n = int(input())
data = input().split()
print(" ".join(data))
for i in range(1, n):
    j = i - 1
    data = list(map(int, data))
    while j >= 0 and data[j] >data[j+1]:
        data[j], data[j+1] = data[j+1], data[j]
        j -= 1
    print(" ".join(map(str, data)))

