G = []
cnt = 0

def insertionSort(A, n, g):
  for i in range(g, n):
    v = A[i]
    j = i - g
    while j >= 0 and A[j] > v:
      global cnt
      cnt += 1
      A[j+g] = A[j]
      j -= g
    A[j+g] = v

def shellSort(n, A):
  m = 1
  while m <= n / 9:
    m = m * 3 + 1
  while 0 < m:
    global G
    G.append(m)
    insertionSort(A, n, m)
    m = int(m / 3)

A = []
n = int(input())

for i in range(n):
  A.append(int(input()))

shellSort(n, A)

print(len(G))
print(*G)
print(cnt)

for i in range(n):
  print(A[i])
