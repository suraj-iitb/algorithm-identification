def bubblesort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N - 1, 0, -1):
            if A[j] < A[j - 1]:
                A[j-1], A[j] = A[j], A[j-1]
                flag = 1
                count += 1
    return A, count
    
N = int(input())
A = list(map(int, input().split()))
A, count = bubblesort(A, N)
print(*A)
print(count)
