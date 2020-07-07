import sys
sys.setrecursionlimit(10**6)


N = int(input())
A = list(map(int, input().split()))
INF = float('inf')
cnt = 0


def merge(left, mid, right):
    global cnt
    L = A[left:mid]+[INF]
    R = A[mid:right]+[INF]
    l = 0
    r = 0

    for i in range(right-left):
        cnt += 1
        if L[l] < R[r]:
            A[left+i] = L[l]
            l += 1
        else:
            A[left+i] = R[r]
            r += 1


def merge_sort(left, right):
    if left+1 < right:
        mid = (left+right)//2
        merge_sort(left, mid)
        merge_sort(mid, right)
        merge(left, mid, right)


merge_sort(0, N)
print(*A)
print(cnt)

