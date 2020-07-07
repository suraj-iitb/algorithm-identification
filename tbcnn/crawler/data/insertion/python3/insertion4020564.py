n = int(input())
a = list(map(int,input().split()))

def allprint(a, n):
  for i in range(n):
    if i > 0:
      print(" ",end="")
    print(a[i],end="")
  print("")

def insertionSort(a, n):
  for i in range(1,n):
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
      a[j + 1] = a[j]
      j -= 1
    a[j + 1] = v
    allprint(a,n)

allprint(a,n)
insertionSort(a,n)
