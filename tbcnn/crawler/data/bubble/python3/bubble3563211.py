N = int(input())
list = list(input().split())

flag = 1
count = 0
while flag == 1:
  flag = 0
  for i in range(N - 1, 0, -1):
    if int(list[i]) < int(list[i - 1]):
      tmp = list[i]
      list[i] = list[i - 1]
      list[i - 1] = tmp
      count += 1
      flag = 1
print(' '.join(list))
print(count)

