def counting_sort(A, B, k):
    C = [0 for i in range(k)]
    for j in range(n):
        C[A[j]] += 1
    #C[i] now contains the number of elements equal to i

    for i in range(1, k):
        C[i] += C[i - 1]
    #C[i] now contains the number of elements less than or equal to i

    for j in range(n - 1, -1, -1):
        B[C[A[j]] - 1] = A[j]
        C[A[j]] -= 1


n = int(input())
A = list(map(int, input().split()))

k = max(A) + 1
B = [0 for _ in range(n)]


counting_sort(A, B, k)
print(*B)
