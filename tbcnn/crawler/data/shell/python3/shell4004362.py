def insertionSort(A,n,g):
  global count
  for i in range(g,n,1):
    v=A[i]
    j=i-g
    while (j >= 0) & (A[j] > v):
      A[j+g] = A[j]
      j = j - g
      count +=1
    A[j+g] = v

n = int(input())
A = [int(input()) for i in range(n)] 

count = 0
G = [1]
while n > 1 + 3*G[-1]:
  G.append(1 + 3*G[-1])
m = len(G)
G.reverse()
for i in range(m):
    insertionSort(A, n, G[i])
    
print(m)
print(*G)
print(count)
print(*A, sep='\n')
