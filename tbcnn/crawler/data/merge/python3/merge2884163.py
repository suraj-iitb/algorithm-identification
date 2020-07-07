global cnt
cnt = 0

def merge(A, left, mid, right):
    L = A[left:mid] + [float("inf")]
    R = A[mid:right] + [float("inf")]

    i = 0
    j = 0
    global cnt
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

        cnt += 1

def mergesort(A, left, right):
    rsl = []
    if left+1 < right:
        mid = int((left+right)/2)
        mergesort(A, left, mid)
        mergesort(A, mid, right)
        rsl = merge(A, left, mid, right)

    return rsl

n = int(input())
S = list(map(int, input().split()))

mergesort(S, 0, n)
print(*S)
print(cnt)
