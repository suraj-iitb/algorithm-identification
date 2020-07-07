"""
マージソート
分割統治法に基づく高速なアルゴリズム。
merge(A, left, mid, right)
  n1 = mid - left;
  n2 = right - mid;
  L[0...n1], R[0...n2] を生成
  for i = 0 to n1-1
    L[i] = A[left + i]
  for i = 0 to n2-1
    R[i] = A[mid + i]
  L[n1] = INFTY
  R[n2] = INFTY
  i = 0
  j = 0
  for k = left to right-1
    if L[i] <= R[j]
      A[k] = L[i]
      i = i + 1
    else 
      A[k] = R[j]
      j = j + 1

mergeSort(A, left, right)
  if left+1 < right
    mid = (left + right)/2;
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)
"""

def merge(A,left,mid,right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = A[left:left+n1] + [10**9+7]
    R = A[mid:mid+n2] + [10**9+7]
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

def mergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2
        mergeSort(A, left, mid)
        mergeSort(A, mid, right)
        merge(A,left,mid,right)

n = int(input())
As = list(map(int, input().split()))
cnt = 0
mergeSort(As,0,n)
print(*As)
print(cnt)
