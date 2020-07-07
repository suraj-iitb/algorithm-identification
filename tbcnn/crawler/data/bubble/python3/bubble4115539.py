def bubble_sort(A, N):
    flag = 1
    c = 0
    while flag:
        flag = 0
        for j in range(1, N):
            if A[j-1] > A[j]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = 1
                c += 1
        N -= 1
    return A, c

N = int(input())
A = list(map(int, input().split()))
A, c = bubble_sort(A, N)
print(' '.join(map(str, A)))
print(c)
