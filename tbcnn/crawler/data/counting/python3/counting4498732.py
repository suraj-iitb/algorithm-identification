def countng_sort(a):
  MAX = 10000
  n = len(a)
  b = [None] * n
  c = [0] * MAX
  
  for i in range(n):
      c[a[i]] += 1
  
  for i in range(1, MAX):
      c[i] += c[i - 1]
  
  for i in reversed(range(0, n)):
      b[c[a[i]] - 1] = a[i]
      c[a[i]] -= 1

  return b

n = int(input())
a = [int(i) for i in input().split()]
print(*countng_sort(a))

