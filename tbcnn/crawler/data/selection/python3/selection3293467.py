N = int(input())
A = list(map(int, input().split()))

def selectionSort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            count += 1
    return count

c = selectionSort(A, N)
for i in range(len(A)):
    if i != len(A) - 1:
        print(A[i], end=" ")
    else:
        print(A[i])
print(c)
