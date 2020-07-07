n=int(input())
a=[int(i) for i in input().split()]


def ss(array, length):
  cnt=0
  for i in range(length):
    minj = i
    v = array[i]
    for j in range(i, n):
      if array[minj]>array[j]:
        minj = j
    if array[i] != array[minj]:
      cnt+=1
    array[i] = array[minj]
    array[minj] = v
  return array, cnt

b, c = ss(a, n)

for i in range(n):
  if i==n-1:
    print(b[i], end='')
  else:
    print(b[i], end=' ')

print()
print(c)
