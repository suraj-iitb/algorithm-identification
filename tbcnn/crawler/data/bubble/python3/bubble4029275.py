def show (a,n):
  for i in range(n):
    if i > 0:
      print("",end=" ")
    print(a[i],end="")
  print("")

def bubbleSort(a,n):
  flag = 1
  count = 0
  while flag:
    flag = 0
    for j in range(n-1,0,-1):
      if a[j] < a[j-1]:
        a[j-1],a[j] = a[j],a[j-1]
        flag = 1
        count += 1
  show(a,n)
  print(count)

n = int(input())
a = list(map(int,input().split()))

bubbleSort(a,n)
