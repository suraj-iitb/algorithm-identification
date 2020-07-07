n = int(input())
arr = list(map(int, input().split()))

for i in range(n):
  v = arr[i]
  j = i - 1
  while j >= 0 and arr[j] > v:
    arr[j + 1] = arr[j]
    j -= 1
  arr[j+1] = v
  print (" ".join([str(x) for x in arr]))
