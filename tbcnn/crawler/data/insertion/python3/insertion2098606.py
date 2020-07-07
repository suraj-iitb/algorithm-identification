def insertion_sort(arr):
  print(" ".join(map(str, arr)))
  for i in range(1, len(arr)):
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j -= 1
    arr[j + 1] = key
    print(" ".join(map(str, arr)))

n = int(input())
arr = list(map(int, input().split()))
insertion_sort(arr)
