N = int(input())
A = list(map(int, input().split(" ")))
num_of_swp = 0

for i in range(N):
  mini = i

  for j in range(i + 1, N):
    if A[j] < A[mini]: mini = j

  if i != mini:
    A[i], A[mini] = A[mini], A[i]
    num_of_swp += 1

print(" ".join(map(str, A)))
print(num_of_swp)
