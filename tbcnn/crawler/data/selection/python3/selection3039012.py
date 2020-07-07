# Selection Sort

length = int(input())
array = [int(i) for i in input().rstrip().split()]

count = 0
for i in range(length):
    minj = i
    for j in range(i, length):
        if array[j] < array[minj]:
            minj = j
    if minj != i:
        count += 1
        array[i], array[minj] = array[minj], array[i]

for i in range(length):
    if i < length - 1:
        print(array[i], end = " ")
    else:
        print(array[i])
print(count)

