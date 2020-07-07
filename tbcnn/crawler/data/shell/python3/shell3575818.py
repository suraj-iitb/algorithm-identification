#ALDS1_2_D
def insertionSort(A, n, g, cnt):
  for i in range(g, n):
    v = A[i]
    j = i - g
    while j >= 0 and A[j] > v:
      A[j+g] = A[j]
      j = j - g
      cnt += 1
    A[j+g] = v
  return A, cnt

def genG(n):
  G = []
  y = 1
  x = 1
  while y <= n:
    G.append(y)
    y = y + 3**x    
    x += 1
  return G[::-1]
    
n = int(input())
A = []
for ni in range(n):
  A.append(int(input()))
cnt = 0
G = genG(n)
m = len(G)
print(m)
print(" ".join([str(i) for i in G]))
for mi in range(m):
  A, cnt = insertionSort(A, n, G[mi], cnt)
print(cnt)
for ni in range(n):
  print(A[ni])
