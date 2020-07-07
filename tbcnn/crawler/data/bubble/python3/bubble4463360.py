def bubble_sort(a,n):
  flag = 1
  cnt = 0
  while flag:
    flag = 0
    for i in range(1,n)[::-1]:
      if a[i] < a[i-1]:
        temp = a[i-1]
        a[i-1] = a[i]
        a[i] = temp
        flag = 1
        cnt += 1
  print(' '.join(map(str,a)))
  print(cnt)
num = int(input())
ar = list(map(int,input().split()))

bubble_sort(ar,num)

