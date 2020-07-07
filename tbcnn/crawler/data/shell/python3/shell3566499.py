import sys
N = int(input())
# list = list(input() for _ in range(N))
list = [int(i) for i in sys.stdin.readlines()] # こっちのが早い

def insertionSort(N, g):
  c = 0
  for i in range(g, N):
    v = list[i]
    j = i - g
    while j >= 0 and list[j] > v:
      list[j+g] = list[j]
      j -= g
      c += 1
    list[j+g] = v
  return c

# def shell_sort(n):
  #数列Gの作成

cnt = 0
m = 0
G = []

h = 1
while h <= N:
  G.insert(0, h)
  h = 3 * h + 1
for i in range(len(G)):
  cnt += insertionSort(N, G[i])

print(len(G))
print(' '.join(map(str, G)))
print(cnt)
for i in range(N):
  print(list[i])


