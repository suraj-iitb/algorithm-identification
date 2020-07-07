def show (a,n):
  for i in range(n):
    if i > 0:
      print("",end=" ")
    print(a[i],end="")
  print("")

def selectionSort(a,n):
  count = 0
  for i in range(n):
    minj = i
    for j in range(i,n):
      if a[j] < a[minj]:
        minj = j
    a[minj],a[i] = a[i],a[minj]
    if minj != i:
      count += 1
  show(a,n)
  print(count)

n = int(input())
a = list(map(int,input().split()))

selectionSort(a,n)
