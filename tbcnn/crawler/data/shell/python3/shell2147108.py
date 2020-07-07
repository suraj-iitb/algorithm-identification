def insertion_sort(A, n, g, cnt):
  for i in range(g, n):
    v = A[i]
    j = i - g
    while j >= 0 and A[j] > v:
      A[j + g] = A[j]
      j = j - g
      cnt += 1
    A[j + g] = v
  return cnt

def shell_sort(A, n):
  cnt = 0
  G = []
  h = 1
  while h <= n:
    G.append(h)
    h = h * 3 + 1
  m = len(G)
  G = G[::-1]

  for i in range(m):
    cnt = insertion_sort(A, n, G[i], cnt)

  return m, G, cnt

data = []
for i in range(int(input())):
  data.append(int(input()))

m, G, cnt = shell_sort(data, len(data))
print(m)
print(" ".join(map(str, G)))
print(cnt)
for i in data: print(i)
