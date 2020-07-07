def print_list(A):
    print(*A, sep=" ")

def insertion_sort(A, n):
    print_list(A)
    for i in range(1, n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print_list(A)

n = int(input())
A = list(map(int,input().split()))

insertion_sort(A, n)
