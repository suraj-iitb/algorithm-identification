flag = 0

N = int(input())

l = list(map(int, input().split()))

for i in range(N-1):
  for j in range(N-1):
    if l[N-1-j] < l[N-2-j]:
      a = l[N-1-j]
      b = l[N-2-j]
      l[N-2-j] = a
      l[N-1-j] = b
      flag += 1

print(" ".join(map(str, l)))
print(flag)
