def insertionSort(a, n, g):
  global cnt
  for i in range(g, n):
    v = a[i]
    j = i - g
    while j >= 0 and a[j] > v:
      a[j + g] = a[j]
      j = j - g
      cnt += 1
    a[j + g] = v

def shellSort(a, n):
  global cnt
  cnt = 0
  g = []
  h = 1
  while h <= len(a):
    g.append(h)
    h = 3 * h + 1
  g.reverse()
  m = len(g)
  for i in range(0, m):
    insertionSort(a, n, g[i])
  print(m)
  print(" ".join(map(str, g)))
  print(cnt)
  for c in a:
    print(c)

n = int(input())
a = [int(input()) for _ in range(n)]
shellSort(a,n)
