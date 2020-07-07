from sys import stdin

INF = 1000000007

def merge(A, l, m, r):
    global count
    L = A[l:m] + [INF]
    R = A[m:r] + [INF]
    li = 0
    ri = 0
    for j in range(l, r):
        count += 1
        if L[li] <= R[ri]:
            A[j] = L[li]
            li += 1
        else:
            A[j] = R[ri]
            ri += 1

def mergeSort(A, l, r):
    if r-l > 1:
        mid = l + (r-l)//2
        mergeSort(A, l, mid)
        mergeSort(A, mid, r)
        merge(A, l, mid, r)

n = int(stdin.readline().rstrip())
S = [int(x) for x in stdin.readline().rstrip().split()]
count = 0
mergeSort(S, 0, n)
print(*S)
print(count)
