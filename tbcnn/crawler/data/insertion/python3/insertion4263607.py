def insertion_sort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        print(' '.join(list(map(str, A))))
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
    print(' '.join(list(map(str, A))))

N = int(input())
A = list(map(int, input().split()))
insertion_sort(A, N)
