count = 0

def merge(array, left, mid, right):
  global count

  n1 = int(mid - left)
  n2 = int(right - mid)

  l = array[left:mid]
  r = array[mid:right]
  
  l.append(9999999999)
  r.append(9999999999)

  i, j = 0, 0

  for k in range(left, right):
    count += 1
    if l[i] <= r[j]:
      array[k] = l[i]
      i += 1
    else:
      array[k] = r[j]
      j += 1

def mergeSort(array, left, right):
  if left + 1 < right:
    mid = int((left + right) / 2)
    mergeSort(array, left, mid)
    mergeSort(array, mid, right)
    merge(array, left, mid, right)

n = int(input())
array = [int(i) for i in input().split()]
mergeSort(array, 0, n)
print(*array)
print(count)

