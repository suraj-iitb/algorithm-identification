n = int(input())
array = list(map(int, input().split()))

swap_num = 0
for i in range(n):
    for j in reversed(range(1, n)):
        if array[j] < array[j-1]:
            array[j], array[j-1] = array[j-1], array[j]
            swap_num += 1
print(' '.join([str(e) for e in array]))
print(swap_num)
