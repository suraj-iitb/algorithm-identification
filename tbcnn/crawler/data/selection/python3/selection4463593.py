def selection_sort(a,n):
  cnt = 0
  for i in range(0,n):
    minj = i
    for j in range(i,n):
      if a[j] < a[minj]:
        minj = j
    if a[i] != a[minj]:
      temp = a[i]
      a[i] = a[minj]
      a[minj] = temp
      cnt += 1
  print(' '.join(map(str,a)))
  print(cnt)
  
num = int(input())
array = list(map(int,input().split()))

selection_sort(array,num)
