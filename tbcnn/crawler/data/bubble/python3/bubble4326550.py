def bubbleSort(matrix, N):
  flag = 1
  count = 0
  j = 0
  while flag == 1:
    flag = 0
    for i in reversed(range(j + 1, N)):
      if matrix[i] < matrix[i-1]:
        matrix[i], matrix[i-1] = matrix[i-1], matrix[i]
        flag = 1
        count += 1
    j += 1

  return count

n = int(input())
A = list(map(int, input().split()))
count = bubbleSort(A, n)
print(" ".join(map(str, A)))
print(count)

