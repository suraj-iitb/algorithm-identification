def insertion_sort(A, n, g):
  global cnt
  for i in range(g, n):
    v = A[i]
    j = i - g
    while j >= 0 and A[j] > v:
      A[j+g] = A[j]
      j -= g
      cnt += 1
    A[j+g] = v


def shell_sort(A, n):
  global cnt
  cnt = 0
  G = [1]
  for i in range(100):
    if G[-1]*3 + 1 > n:
      break 
    G.append(G[-1]*3 + 1)
  G.reverse()
  m = len(G)

  for i in range(m):
    insertion_sort(A, n, G[i])

  print(m)
  print(*G)


n = int(input())
A = [int(input()) for _ in range(n)]
shell_sort(A, n)
print(cnt)
print(*A, sep='\n')
