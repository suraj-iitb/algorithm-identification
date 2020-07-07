import sys
input = sys.stdin.readline
MAX = 500000
SENTINEL = 2000000000
L = [0]*(MAX//2 + 2)
R = [0]*(MAX//2 + 2)
cnt = 0

def Merge(A,n,left,mid,right,cnt):
    n1 = mid - left
    n2 = right - mid
    for i in range(n1):
        L[i] = A[left + i]
    for i in range(n2):
        R[i] = A[mid + i]
    L[n1] = SENTINEL
    R[n2] = SENTINEL
    L_i = 0
    R_i = 0
    for k in range(left,right):
        cnt += 1
        if L[L_i] <= R[R_i]:
            A[k] = L[L_i]
            L_i += 1
        else:
            A[k] = R[R_i]
            R_i += 1
    return cnt

def MergeSort(A,n,left,right,cnt):
    if left + 1 < right:
        mid = (left + right)//2
        cnt = MergeSort(A,n,left,mid,cnt)
        cnt = MergeSort(A,n,mid,right,cnt)
        cnt = Merge(A,n,left,mid,right,cnt)
    return cnt

if __name__ == "__main__":
    n = int(input())
    array = list(map(int,input().split()))
    cnt = 0
    SENTINEL = 2*10**9
    cnt = MergeSort(array,n,0,n,cnt)
    print(" ".join(map(str,array)))
    print(cnt)

