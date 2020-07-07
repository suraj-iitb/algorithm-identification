n = int(input())
A = [int(i) for i in input().split(' ')]
# A = '0 33 43 62 29 0 8 52 56 56 19 11 51 43 5 8 93 30 66 69'.split(' ')
# A = [int(i) for i in A]

def trace(A):
    for index, v in enumerate(A):
        print(v, end='')
        if index != len(A) - 1:
            print(' ', end='')
    print()

def bubble_sort(A, n):
    i = 0
    counter = 0
    while i <= n - 1:
        j = n - 1
        while j >= i + 1:
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                counter += 1
            j -= 1
        i += 1
    trace(A)
    print(counter)

bubble_sort(A, n)
