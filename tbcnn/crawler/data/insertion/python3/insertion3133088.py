N = int(input())
A = [int(i) for i in input().split()]
 
def insertionSort(arr):
    arr_len = len(arr)
    for i in range(arr_len):
        v = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > v :
            A[j +1] =A[j]
            j = j -1
        arr[j+1] = v
        print(' '.join([str(x) for x in arr]))
 
insertionSort(A)
