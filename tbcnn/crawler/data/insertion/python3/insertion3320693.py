N = int(input().rstrip())
A = list(map(int, input().rstrip().split()))

def insertion_sort(A, N):
    for i in range(N):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key

        string = list(map(str, A))
        print(' '.join(string))

insertion_sort(A, N)      
