INF = 10000000000
def merge(A,left,mid,right):
  count = 0
  L = A[left:mid] + [INF]
  R = A[mid:right] + [INF]
  i,j = 0,0
  for k in range(left, right):
    count += 1
    if L[i] <= R[j]:
      A[k]=L[i]
      i += 1
    else:
      A[k]=R[j]
      j += 1
  return count
def merge_sort(A,left,right):
  if left+1 < right:
    mid = (left+right)//2
    count_l = merge_sort(A,left,mid)
    count_r = merge_sort(A,mid,right)
    return merge(A,left,mid,right) + count_l + count_r
  return 0


n = int(input())
A = [int(i) for i in input().split()]
count = merge_sort(A, 0, n)
for i in range(n):
  if i:
    print(" ", end = "")
  print(A[i], end = "")
print()
print(count)  

