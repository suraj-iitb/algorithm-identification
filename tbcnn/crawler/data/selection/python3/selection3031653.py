def print_list(A):
    print(*A, sep=" ")

def swap(a, b):
    return b, a

def find_minj(A, i, n):
    minj = i
    for j in range(i, n):
        if A[j] < A[minj]:
            minj = j
    return minj

def selection_sort(A, n):
    replace_num = 0
    for i in range(0, n):
        minj = find_minj(A, i, n)
        if A[i] > A[minj]:
            A[i], A[minj] = swap(A[i], A[minj])
            replace_num += 1
    print_list(A)
    print(replace_num)

n = int(input())
A = list(map(int,input().split()))

selection_sort(A, n)
