n = int(input())
array = list(map(int, input().split()))
swaped = 0

for i in range(n):
    mini = array[i]
    mini_idx = i
    for j in range(i, n):
        if mini > array[j]:
            mini = array[j]
            mini_idx = j
    if i != mini_idx:
        array[i], array[mini_idx] = array[mini_idx], array[i]
        swaped += 1
print(' '.join([str(e) for e in array]))
print(swaped)
