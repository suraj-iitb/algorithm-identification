n = int(input())
array =list(map(int, input().split()))

min_index = 0
count = 0
for i in range(n):
    min_index = i
    for j in range(i+1, n):
        if array[min_index] > array[j]:
            min_index = j
    if array[i] != array[min_index]:
        array[i], array[min_index] = array[min_index], array[i]
        count += 1
print(' '.join(map(str, array)))
print(count)
