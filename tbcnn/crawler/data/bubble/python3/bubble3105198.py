def bubbleSort(a,n):
  flag = 1
  count = 0
  while flag:
    flag = 0
    for j in range(n-1,0,-1):
      if a[j] < a[j-1]:
        count += 1
        w = a[j]
        a[j] = a[j-1]
        a[j-1] = w
        flag = 1
  print(' '.join(map(str, a)))
  print(count)

n = int(input())
a = list(map(int, input().split()))
bubbleSort(a,n)
