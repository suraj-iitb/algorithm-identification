n, data = int(input()), list(map(int, input().split()))
i, t = 0, 0
while i != n-1:
    for j in range(n-1, i, -1):
        if data[j-1] > data[j]:
            data[j-1], data[j] = data[j], data[j-1]
            t += 1
    i += 1
print(" ".join(map(str, data)))
print(t)

