import sys
cnt=0
n=int(input())
A = list(map(int,sys.stdin))

def insertionSort(A,n,g):
  global cnt
  for i in range(g,n):
    v=A[i]
    j=i-g
    while j>=0 and A[j]>v:
      A[j+g]=A[j]
      j=j-g
      cnt+=1
    A[j+g]=v
  return A

m=1
G=[1]
while G[m-1]*3+1<=n:
  G.append(G[m-1]*3+1)
  m+=1
G=sorted(G, reverse=True)

for i in G:
  A=insertionSort(A,n,i)

print(m)
print(*G)
print(cnt)
print('\n'.join(map(str,A)))
