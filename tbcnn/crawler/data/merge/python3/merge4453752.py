count = [0]

def merge(A, left, right, mid, count):
    lstl = A[left: mid] + [5000000000]
    lstr = A[mid: right] + [5000000000]
    pl = 0
    pr = 0
    for _ in range(left, right):
        if lstl[pl] < lstr[pr]:
            A[left + pl + pr] = lstl[pl]
            pl += 1
            count[0] += 1
        else:
            A[left + pr + pl] = lstr[pr]
            pr += 1
            count[0] += 1
    
    

def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, right, mid, count)

import sys
input = sys.stdin.readline

n = int(input())
S = list(map(int, input().split()))

merge_sort(S, 0, n)
print(" ".join(map(str, S)))
print(count[0])
