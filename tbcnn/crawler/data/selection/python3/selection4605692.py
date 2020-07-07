N = int(input())
A = list(map(int, input().split()))

a = 0
for i in range(len(A)-1):
  mini = i
  minv = A[i]
  for j in range(i, len(A)):
    if minv > A[j]:
      mini = j
      minv = A[j]
  if i != mini:
    A[i], A[mini] = A[mini], A[i]
    a += 1

print(" ".join(list(map(str, A))))
print(a)
