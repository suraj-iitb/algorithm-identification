def selectionSort(array):
    n = len(array)
    cnt = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if array[j] < array[minj]:
                minj = j
        array[i], array[minj] = array[minj], array[i]
        if i != minj and array[i] != array[minj]:
            cnt += 1

    return (array, cnt)

n = int(input())
array = [int(x) for x in input().split()]

resultArray, cnt = selectionSort(array)

print(*resultArray)
print(cnt)

