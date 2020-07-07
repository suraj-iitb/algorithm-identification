def bubble_sort(A, N):
    cnt = 0
    flag = True
    while flag:
        flag = False
        for j in range(N - 1, 0, -1):
            if A[j - 1] > A[j]:
                A[j - 1], A[j] = A[j], A[j - 1]
                flag = True
                cnt += 1
    return cnt

N = int(input())
A = list(map(int, input().split()))
cnt = bubble_sort(A, N)
print(*A)
print(cnt)
