#ALDS1_1_A
n = int(input())
a = [int(i) for i in input().split()]
for i in range(1,n):
  print(" ".join([str(t) for t in a]))
  key = a[i]
  j = i - 1
  while j >= 0 and a[j] > key:
    a[j+1] = a[j]
    j -= 1
  a[j+1] = key
print(" ".join([str(t) for t in a]))
