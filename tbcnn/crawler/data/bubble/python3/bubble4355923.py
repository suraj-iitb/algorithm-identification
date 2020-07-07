def BubbleSort(l):
  countSwap = 0
  for i in range(len(l)-1):
    for j in reversed(range(i+1, len(l))):
      if l[j] < l[j-1]:
        temp = l[j]
        l[j] = l[j-1]
        l[j-1] = temp
        countSwap += 1
  print(" ".join(map(str, l)))
  print(countSwap)

N = input()
l = list(map(int, input().split()))
BubbleSort(l)
