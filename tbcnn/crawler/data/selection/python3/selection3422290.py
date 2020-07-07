factor = int(input())
numbers = list(map(int,input().split()))

def selectionsort(array,n):
    counter = 0
    for i in range(len(array)):
        minj = i
        for j in range(i,len(array)):
            if array[j] < array[minj]:
                minj = j
        array[minj],array[i] = array[i],array[minj]
        if minj != i :
            counter += 1
    return counter

repetition = selectionsort(numbers,factor)
print(" ".join(list(map(str,numbers))))
print(repetition)

