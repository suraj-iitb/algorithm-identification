INF = 10000000000

def merge(A, left, mid, right):
  L = A[left:mid] + [INF]
  R = A[mid:right] + [INF]
  i, j = 0, 0
  global count
  for k in range(left, right):
    if L[i] <= R[j]:
        A[k] = L[i]
        i += 1
    else:
        A[k] = R[j]
        j += 1
    count += 1

def merge_sort(A, left, right):
    if (left + 1) < right:
        mid = (left + right) // 2
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
A = list(map(int, input().split()))
count = 0
merge_sort(A, 0, n)

print(*A)
print(count)
