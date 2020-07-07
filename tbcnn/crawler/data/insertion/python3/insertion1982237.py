_ = input()
A = [int(a) for a in input().split(" ")]
for i in range(1, len(A)):
  print(" ".join([str(a) for a in A]))
  key = A[i]
  j = i - 1
  while j >= 0 and A[j] > key:
    A[j + 1] = A[j]
    j -= 1
  A[j + 1] = key
print(" ".join([str(a) for a in A]))
