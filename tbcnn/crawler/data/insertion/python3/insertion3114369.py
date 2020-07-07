def insertion_sort(A, N):
    yield A
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            # 右にずらす
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        yield A

N = int(input())
A = list(map(int, input().split()))
for li in insertion_sort(A, N):
    print(*li)
