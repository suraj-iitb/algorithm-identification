def bubblesort(array):
    flag = True
    res = 0
    while flag:
        flag = False
        for i in range(len(array)-1, 0, -1):
            if array[i] < array[i-1]:
                array[i], array[i-1] = array[i-1], array[i]
                res += 1
                flag = True
    return (array, res)
    
int(input())
arr, c = bubblesort([int(i) for i in input().split()])
print(*arr,sep=' ')
print(c)
