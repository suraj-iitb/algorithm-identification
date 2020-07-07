n = int(input())
lis = list(map(int, input().split()))
print(" ".join(map(str, lis)))
for i in range(1, n):
  v = lis[i]
  j = i - 1
  while j >= 0 and lis[j] > v:
    lis[j+1] = lis[j]
    j -= 1
  lis[j+1] = v
  print(" ".join(map(str, lis)))
