n = int(input())
array = [int(a) for a in input().split()]
for i in range(n):
    j = i
    while j < n:
        if j != 0 and array[j-1] > array[j]:
            array[j-1], array[j] = array[j], array[j-1]
            j -= 1
            continue
        else:
            break
    for k in range(n):
        if k != n-1:
            print(array[k], end=' ')
        else:
            print(array[k])
