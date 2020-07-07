n = int(input())
a = list(map(int, input().split()))
for i in range(n):
  for j in range(1, n):
    if i-j >= 0 and a[i-j] > a[i-j+1]:
      a[i-j], a[i-j+1] = a[i-j+1], a[i-j]
    else:
      break
  print(" ".join([str(i) for i in a]))
