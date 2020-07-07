def insertionSort(A):
    for i in range(1,len(A)):
        print(" ".join([str(i) for i in A]))
        tmp = A[i]
        j = i-1
        while j >= 0 and A[j] > tmp:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = tmp


n = int(input())
a = [int(i) for i in input().split()]


insertionSort(a)
print(" ".join([str(i) for i in a]))

