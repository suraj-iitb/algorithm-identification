def bubblesort(n,l):
  flag=True
  m=0
  c=0
  for j in range(n):
    for i in range(n-1,m,-1):
      if int(l[i])<int(l[i-1]):
        l[i],l[i-1]=l[i-1],l[i]
        
        c+=1
    m+=1
  print(" ".join(l))
  print(c)
n=int(input())
l=list(input().split())
bubblesort(n,l)
