def insertionSort(A,n,g):
  cnt=0
  for i in range(g,n):
    v=A[i]
    j=i-g
    while j>=0 and v<A[j]:
      A[j+g]=A[j]
      j-=g
      cnt+=1
    A[j+g]=v
  return cnt
n=int(input())
A=[int(input()) for _ in range(n)]
cnt_ans=0
G=[]
i=1
while i<=n:
  G.append(i)
  i=i*3+1
G=G[::-1]
m=len(G)
for g in G:
  cnt=insertionSort(A,n,g)
  cnt_ans+=cnt
print(m)
print(*G)
print(cnt_ans)
for i in range(n):
  print(A[i])
