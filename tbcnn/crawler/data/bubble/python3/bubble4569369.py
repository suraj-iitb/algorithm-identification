def bubble_sort(A):
    n = len(A)
    cnt = 0
    for i in range(n-1, 0, -1):
        for j in range(i):
            if A[j] > A[j+1]:
                cnt += 1
                A[j], A[j+1] = A[j+1], A[j]
    return cnt


N = int(input())
A = [int(x) for x in input().split()]
cnt = bubble_sort(A)
print(' '.join(map(str, A)))
print(cnt)

