N = int(input())

lst = [ int(i) for i in input().split() ]

lstr = [ str(c) for c in lst ]
print(" ".join(lstr))

for i in range(1, N):
  v = lst[i]
  j = i - 1
  while 0 <= j and v < lst[j]:
    lst[j + 1] = lst[j]
    j -= 1
  
  lst[j + 1] = v

  lstr = [ str(c) for c in lst]
  print(" ".join(lstr))
