N = int(input())
A = list(map(int, input().split(" ")))

def print_list(A):
    for a in A[:-1]:
        print ("%d "%a, end="")
    print(A[-1])

def SelectionSort(A, N):
    count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            v = A[i]
            A[i] = A[minj]
            A[minj] = v
            count += 1
    return A, count
        
A_sorted, c = SelectionSort(A, N)

print_list(A_sorted)
print(c)
