N = input()
l = [int(i) for i in input().split()]
mapped_l = map(str, l)
print(" ".join(mapped_l))
for i in range(1, len(l)):
  key = l[i]
  j = i-1
  while j >= 0 and l[j] > key:
    l[j+1] = l[j]
    j -= 1
  l[j+1] = key
  mapped_l = " ".join(map(str, l))
  print(mapped_l)

