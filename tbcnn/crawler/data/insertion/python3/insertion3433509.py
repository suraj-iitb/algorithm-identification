def insertion_sort(A):
    global N 
    for i in range(1, N):
        key = A[i]
        j = i - 1
        while A[j] > key and j >= 0:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = key
        print(' '.join(list(map(str, A))))
    return 
N = int(input())
A = list(map(int, input().split()))
print(' '.join(list(map(str, A))))
insertion_sort(A)

