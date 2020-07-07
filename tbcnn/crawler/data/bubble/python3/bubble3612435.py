def bublleSort(A):
    cnt = 0

    for i in range(1, len(A)):
        for j in range(1, len(A) - i + 1):
            if  A[j - 1] > A[j]:
                A[j], A[j - 1] = A[j - 1], A[j]
                cnt += 1

    return A, cnt


N = int(input())
A = list(map(int, input().split()))

A_sorted, cnt = bublleSort(A)

print(*A_sorted)
print(cnt)

