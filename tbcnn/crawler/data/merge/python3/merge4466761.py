cnt = 0
n = int(input())
S = list(map(int, input().split()))

def mergeSort(S, left, right):
  if left+1 < right:
    mid = (left + right) // 2
    mergeSort(S, left, mid)
    mergeSort(S, mid, right)
    merge(S, left, mid, right)

def merge(S, left, mid, right):

  L = S[left:mid] + [10**10]
  R = S[mid:right] + [10**10]

  i,j = 0,0

  global cnt
  for k in range(left, right):
    cnt += 1
    if L[i] <= R[j]:
      S[k] = L[i]
      i += 1
    else:
      S[k] = R[j]
      j += 1

mergeSort(S, 0, len(S))
print (' '.join(map(str,S)))
print (cnt)
