n = int(input())
A = list(map(int, input().split()))

cnt = 0


def bubble_sort(A, n):
    global cnt
    for _ in range(n):
        for i in range(n-1):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                cnt += 1


bubble_sort(A, n)
print(*A)
print(cnt)

