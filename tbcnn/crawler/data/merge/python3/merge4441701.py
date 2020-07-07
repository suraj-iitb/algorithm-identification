import math

def merge(A, left, mid, right, cnt):
    n1 = mid - left
    n2 = right - mid
    L = [0]*(n1+1)
    R = [0]*(n2+1)
    for i in range(n1):
        L[i] = A[left + i]
    for i in range(n2):
        R[i] = A[mid + i]
    L[n1] = math.inf
    R[n2] = math.inf
    i = 0
    j = 0
    for k in range(left,right):
        cnt += 1
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else: 
            A[k] = R[j]
            j += 1
            
    return A, cnt

def mergeSort(A, left, right, cnt):
    if left+1 < right:
        mid = (left + right)//2
        A, cnt = mergeSort(A, left, mid, cnt)
        A, cnt = mergeSort(A, mid, right, cnt)
        A, cnt = merge(A, left, mid, right, cnt)
    return A, cnt
        
n = int(input())
S = list(map(int,input().split()))

S_out, cnt_out = mergeSort(S,0,len(S),0)

S_str = list(map(str,S))
print(" ".join(S_str))
print(str(cnt_out))
