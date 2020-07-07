import sys
input = sys.stdin.readline

if __name__ == '__main__':
  n = int(input())
  A = list(map(int, input().split()))
  cnt = 0

  def merge(A, left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L=[10**9+1]*(n1+1) # 先に入れきった方の配列をヌルポにしないため
    R=[10**9+1]*(n2+1)
    for i in range(n1):
      L[i] = A[left + i]
    for i in range(n2):
      R[i] = A[mid + i]
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
    if left + 1 < right:
      mid = (left + right) // 2
      mergeSort(A, left, mid)
      mergeSort(A, mid, right)
      merge(A, left, mid, right)

  mergeSort(A, 0, n)
  print(*A)
  print(cnt)


