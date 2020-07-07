def insertion(A):
    for i in range(len(A)):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
        print(' '.join([str(x) for x in A]))

N = int(input())
A = [int(x) for x in input().strip().split(' ')]
insertion(A)
