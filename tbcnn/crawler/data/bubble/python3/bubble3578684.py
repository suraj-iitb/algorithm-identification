N = int(input())
A = list(map(int, input().split()))

num = 0
for i in range(1, N):
  while A[i] < A[i-1] and i-1 >= 0:
    temp = A[i-1]
    A[i-1] = A[i] 
    A[i] = temp
    i -= 1
    num += 1
 
print(*A)
print(num)