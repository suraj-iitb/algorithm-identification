def insertion(A, N, g):
  cnt=0
  for i in range(g,N):
    v=A[i]
    j=i-g
    while j >= 0 and A[j]>v:
      A[j+g]=A[j]
      j-=g
      cnt+=1
    A[j+g]=v
  return cnt

def shell(A,n):
  cnt=0
  g=[797161,265720,88573,29524,9841,3280,1093,364,121,40,13,4,1]
  G=[i for i in g if i <= n]
  m=len(G)
  for i in range(m):
    cnt+=insertion(A,n,G[i])
  print(m)
  print(*G)
  print(cnt)
  print(*A,sep='\n')

n=int(input())
A=[0]*n
for i in range(n):
  A[i]=int(input())
shell(A,n)
