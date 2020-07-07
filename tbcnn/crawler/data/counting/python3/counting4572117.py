def countingSort(A, B, k):
    from collections import defaultdict
    C = defaultdict(int)
    for a in A:
        C[a] += 1
    cnt = 0
    for i in range(max(C.keys()) + 1):
        for _ in range(C[i]):
            B[cnt] = i
            cnt += 1


def resolve():
    n = int(input())
    A = [int(i) for i in input().split()]
    B = [0] * n
    countingSort(A, B, max(max(A), n))
    print(*B)

resolve()

