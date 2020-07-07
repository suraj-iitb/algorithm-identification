def SelectionSort(l):
  countSwap = 0
  for i in range(len(l)):
    minj = i
    for j in range(i, len(l)):
      if l[j] < l[minj]:
        minj = j
    if minj == i:
      continue
    else:
      temp = l[i]
      l[i] = l[minj]
      l[minj] = temp
      countSwap += 1
  print(" ".join(map(str, l)))
  print(countSwap)

N = input()
l = list(map(int, input().split()))
SelectionSort(l)
