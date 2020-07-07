N = int(input())
list = list(map(str, input().split()))
print(' '.join(list))

for i in range(1, N):
  v = list[i]
  j = i - 1
  while j >= 0 and int(list[j]) > int(v):
    list[j+1] = list[j]
    j += -1
  list[j+1] = v
  print(' '.join(list))
