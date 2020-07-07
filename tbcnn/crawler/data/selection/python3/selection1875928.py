# Selection sort
def selection_sort(A,N):
    counter = 0
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if not i == minj:
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            counter += 1
    return counter
N = int(input())
A = [int(i) for i in input().split(' ')]
c = selection_sort(A,N)
print(' '.join(list(map(str, A))))
print(c)
