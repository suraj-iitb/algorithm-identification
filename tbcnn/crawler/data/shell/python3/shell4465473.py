def insertion_sort(a,n,g):
  global cnt
  for i in range(g,n):
    temp = a[i]
    j = i - g
    while j >= 0 and a[j] > temp:
      a[j + g] = a[j]
      j = j - g
      cnt += 1
    a[j+g] = temp
    
def shell_sort(a,n):
  h = 1
  g = []
  while h <= n:
    g.append(h)
    h = h * 3 + 1
  m = len(g)
  g = g[::-1]
  for i in range(m):
    insertion_sort(a,n,g[i])
  print(m)
  print(' '.join(map(str,g)))
  print(cnt)
  [print(i) for i in a]
    
num = int(input())
a = []
cnt = 0
for i in range(num):
  a.append(int(input()))
shell_sort(a,num)
print(cnt)
