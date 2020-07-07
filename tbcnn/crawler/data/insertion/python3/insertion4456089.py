def Insertion_Sort(a,n):
  for i in range(1,n+1):
    print(' '.join(map(str,a)))
    if n > i:
      temp = a[i]
      j = i - 1
      while j >= 0 and a[j] > temp:
        a[j+1] = a[j]
        j -= 1
      a[j+1] = temp


num = int(input())
s = list(map(int,input().split()))
Insertion_Sort(s,num)

