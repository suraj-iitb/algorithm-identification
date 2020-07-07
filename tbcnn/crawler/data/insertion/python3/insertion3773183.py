n = int(input())
a = list(map(int, input().split()))
for j in range(n):
  print(a[j], end="")
  if j < n-1:
    print(" ", end="")
  else:
    print("")

for i in range(1, n):
  v = a[i]
  j = i -1
  while(j >= 0 and a[j] > v):
    a[j+1] = a[j]
    j = j - 1
  a[j+1] = v

  for j in range(n):
    print(a[j], end="")
    if j < n-1:
      print(" ", end="")
    else:
      print("")
