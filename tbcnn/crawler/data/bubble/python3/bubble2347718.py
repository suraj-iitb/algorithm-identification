x = int(input())
y = input()
y = list(map(int, y.split()))
r = sorted(y)
c = 0
while y != r:
    for i, j in enumerate(y[:-1]):
        if y[i] > y[i+1]:
            y[i], y[i+1] = y[i+1], y[i]
            c += 1
print(*y)
print(c)
