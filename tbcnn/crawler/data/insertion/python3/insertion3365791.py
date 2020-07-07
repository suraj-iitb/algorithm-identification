def insertion_sort(A):
    for i in range(1, len(A)):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        print(' '.join([str(x) for x in A]))


n = int(input())
A = [int(x) for x in input().split()]

print(' '.join([str(x) for x in A]))

insertion_sort(A)

