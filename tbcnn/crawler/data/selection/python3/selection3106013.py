def selectionSort(a, n):
  count = 0
  for i in range(0, n):
    minj = i
    for j in range(i, n):
      if a[j] < a[minj]:
        minj = j
    if i != minj:
      w = a[i]
      a[i] = a[minj]
      a[minj] = w
      count += 1
  print(' '.join(map(str, a)))
  print(count)

n = int(input())
a = list(map(int, input().split()))
selectionSort(a, n)
