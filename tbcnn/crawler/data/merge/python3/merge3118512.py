n = int(input())
S = list(map(int, input().split()))

def merge(A, left, mid, right):
    cnt = 0
    n1 = mid - left
    n2 = right - mid
    L = [0]*(n1+1)
    R = [0]*(n2+1)
    for i in range(n1):
        L[i] = A[left + i]
    for i in range(n2):
        R[i] = A[mid + i]
    L[n1] = float("inf")
    R[n2] = float("inf")
    i = 0
    j = 0
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    return cnt
            
def merge_sort(A, left, right):
    if left + 1 < right:
        mid = (left + right)//2
        cnt_left = merge_sort(A, left, mid)
        cnt_right = merge_sort(A, mid, right)
        cnt_merge = merge(A, left, mid, right)
        cnt = cnt_left + cnt_right + cnt_merge
    else:
        cnt = 0
    return cnt

cnt = merge_sort(S, 0, n)
print(' '.join( map(str, S) ))
print(cnt)
