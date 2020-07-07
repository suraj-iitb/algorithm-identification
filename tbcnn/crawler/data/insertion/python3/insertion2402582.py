N = int(input())
A = list(map(int, input().split(" ")))

def print_list(A):
    for a in A[:-1]:
        print ("%d "%a, end="")
    print(A[-1])

def InsertionSort(A, N):
    print_list(A)
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print_list(A)

InsertionSort(A, N)
