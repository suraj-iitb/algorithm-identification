def insertionSort(A, N):
    for i in range(len(A)):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(' '.join([str(s) for s in A]))

input_line = input()
N = int(input_line)
input_line = input()
A = [int(s) for s in input_line.split(' ') if s]
insertionSort(A, N)
