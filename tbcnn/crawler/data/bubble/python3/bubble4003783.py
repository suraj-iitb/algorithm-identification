n=int(input())
A=[int(i) for i in input().split()]

flag=1
count=0

while flag==1:
  flag=0
  for i in range(n-1,0,-1):
    if A[i-1] > A[i]:
      v =A[i]
      A[i] = A[i-1]
      A[i-1] =v
      flag=1
      count+=1
print(*A, sep=' ')
print(count)
