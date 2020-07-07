n = int(input())
data = list(map(int, input().split()))
counter = 0
for i in range(n):
    num_min = float('inf')
    num_index = i
    for j in range(i, n):
        if data[j] < num_min:
            num_min = data[j]
            num_index = j
    if data[i] != data[num_index]:
        data[i], data[num_index] = data[num_index], data[i]
        counter += 1
print(*data)
print(counter)

