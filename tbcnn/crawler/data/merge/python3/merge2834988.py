cnt = 0

def merge(array, left, middle, right):
    n1 = middle - left
    n2 = right - middle
    L = array[left:left + n1] + [float("inf")]
    R = array[middle:middle + n2] + [float("inf")]
    i = 0
    j = 0
    for k in range(left, right):
        global cnt
        cnt += 1
        if L[i] <= R[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = R[j]
            j += 1


def mergeSort(array, left, right):
    if left + 1 < right:
        middle = int((left + right) / 2.)
        mergeSort(array, left, middle)
        mergeSort(array, middle, right)
        merge(array, left, middle, right)


n = int(input())
array = [int(x) for x in input().split()]
mergeSort(array, 0, len(array))
print(*array)
print(cnt)
