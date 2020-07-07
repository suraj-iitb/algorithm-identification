n = int(input())
array = list(map(int, input().split()))
count = 0

for i in range(n):
    flag = 0
    minj = i
    for j in range(i, n):
        if array[j] < array[minj]:
            flag = 1
            minj = j

    if flag == 1:
        count += 1
    array[minj], array[i] = array[i], array[minj]


print(*array)
print(count)

