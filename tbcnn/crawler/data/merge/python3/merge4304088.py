# Merge sort マージソート
# 与えられたリストAをマージソートして返す。
def mergesort(A, left, right):
    mid = int((left + right) / 2)
    if left + 1 >= right:
        return 0
    else:
        cnt = 0
        cnt += mergesort(A, left, mid)
        cnt += mergesort(A, mid, right)
        cnt += merge(A, left, mid, right)
        return cnt


def merge(A, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]
    l1, l2 = len(L), len(R)
    i1, i2 = 0, 0
    L += [2000000000]
    R += [2000000000]
    cnt = 0
    for k in range(l1 + l2):
        cnt += 1
        if L[i1] <= R[i2]:
            A[left + k] = L[i1]
            i1 += 1
        else:
            A[left + k] = R[i2]
            i2 += 1
    return cnt


n = int(input())
S = [int(i) for i in input().split()]
mergecnt = mergesort(S, 0, n)
for i in range(0, n - 1):
    print(S[i], end=" ")
print(S[n - 1])
print(mergecnt)

