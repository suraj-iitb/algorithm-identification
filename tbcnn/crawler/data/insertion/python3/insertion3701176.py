from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(_) for _ in stdin.readline().rstrip().split()]

def insertion_sort(A, N):
    print(' '.join(str(_) for _ in A))
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j-=1
        A[j+1] = v
        print(' '.join(str(_) for _ in A))

insertion_sort(A, N)
