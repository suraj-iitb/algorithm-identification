N = int(input())
list = list(input().split())

count = 0
for i in range(N):
  minj = i
  for j in range(i, N):
    if int(list[j]) < int(list[minj]):
      minj = j

  tmp = list[i]
  list[i] = list[minj]
  list[minj] = tmp
  if minj != i: count += 1
print(' '.join(list))
print(count)
