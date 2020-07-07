def trace(A, N):
    print(*A)

def insertion_sort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i -1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        trace(A, N)


N = int(input())
A = list(map(int, input().split()))
trace(A, N)
insertion_sort(A, N)
