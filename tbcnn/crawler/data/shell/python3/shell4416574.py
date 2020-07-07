cnt = 0
def insertionSort(A, n, g):
  global cnt
  for i in range(g,n):
    v = A[i]
    j = i - g
    while (j >= 0 and A[j] > v ):
      A[j+g] = A[j]
      j = j - g
      cnt += 1
    A[j+g] = v

def shellSort(A, n):
  global cnt
  cnt = 0
  
  m = 0
  b=n
  while b > 0:
    b = b // 4
    m += 1
    
  G = []
  base = 1
  for i in range(0,m):
    G.insert(0,base)
    base = base * 3 + 1

  print(m)
  strG = [str(i) for i in G]
  print(" ".join(strG))
  for i in range(m):
    insertionSort(A, n, G[i])

N = int(input())
A = list()
for i in range(N):
  A.append(int(input()))

shellSort(A,N)
print(cnt)
for a in A:
  print(a)
        
        
        
        
