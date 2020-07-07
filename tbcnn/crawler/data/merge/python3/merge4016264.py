n = int(input())
A = list(map(int, input().split()))

count = 0

inf = 999999999999999999

def mergeSort(left, right):
  if right - left <= 1:
    return A[left:right]
  mid = (left + right) // 2
  return merge(mergeSort(left, mid), mergeSort(mid, right))

def merge(left, right):
  global count
  result = []
  
  left.append(inf)
  right.append(inf)
  left_i = 0
  right_i = 0
  while True:
    if right[right_i] == inf:
      result.extend(left[left_i:-1])
      count += len(left[left_i:-1])
      break
    if left[left_i] == inf:
      result.extend(right[right_i:-1])
      count += len(right[right_i:-1])
      break

    if left[left_i] < right[right_i]:
      result.append(left[left_i])
      left_i += 1
    else:
      result.append(right[right_i])
      right_i += 1
    count += 1
  return result

print(*mergeSort(0, n))
print(count)
