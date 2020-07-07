def bubbleSort(array):
    n = len(array)
    cnt = 0
    flag = True
    while flag:
        flag = False
        for i in range(n-1, 0, -1):
            if array[i-1] > array[i]:
                array[i-1], array[i] = array[i], array[i-1]
                flag = True
                cnt += 1
    return (array, cnt)

n = int(input())
array = [int(x) for x in input().split()]

resultArray, cnt = bubbleSort(array)

print(*resultArray)
print(cnt)
