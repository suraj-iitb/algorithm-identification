n=int(input())
A=[int(i) for i in input().split()]

for i in range(n):
  v =A[i]
  j=i-1
  while (j>=0)&(A[j]>v):
    #print('i=', i)
    #print('j=',j)
    A[j+1]=A[j]
    A[j] = v
    j-=1
  print(*A, sep=' ')
