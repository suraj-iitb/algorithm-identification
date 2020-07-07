
def selsort(array):
    counter = 0
    for i in range(len(array)):
        minnum = i
        for c in range(i,len(array)):
            if array[c] < array[minnum]:
                minnum = c
        if minnum != i:
            x = array[i]
            array[i] = array[minnum]
            array[minnum] = x
            counter = counter + 1
    array.append(counter)

N = int(input())
arr = [int(i) for i in input().split()]

selsort(arr)
print(' '.join([str(i) for i in arr[:-1]]))
print(arr[-1])
