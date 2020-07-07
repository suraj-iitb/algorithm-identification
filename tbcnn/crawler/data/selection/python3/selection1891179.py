n = int(input())
data = list(map(int, input().split()))

nb_exchange = 0
for i in range(n):
    minj = i
    for j in range(i, n):
        if data[j] < data[minj]:
            minj = j

    if i != minj:
        nb_exchange += 1
        data[i], data[minj] = data[minj], data[i]

print(" ".join(map(str, data)))
print(nb_exchange)
