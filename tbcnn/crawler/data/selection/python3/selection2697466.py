n, data = int(input()), list(map(int, input().split()))
idx, t = 0, 0
for i in range(n-1):
    for j in range(i+1, n):
        if j == i+1:
            idx = j
        elif data[idx] > data[j]:
            idx = j
    if data[i] > data[idx]:
        data[i], data[idx] = data[idx], data[i]
        t += 1
print(" ".join(map(str, data)))
print(t)

