n=int(input())
A=list(map(int,input().split()))
B=[0]*n

def countingSort(A,B,k):
  C=[0]*(k+1)

  for j in range(n):
    C[A[j]]+=1
  
  for i in range(1,k+1):
    C[i]=C[i]+C[i-1]

  for j in reversed(range(0,n)):
    #print(A[j])
    #print(C[A[j]])
    #print(B[C[A[j]]])
    #print('---')
    B[C[A[j]]-1]=A[j]
    C[A[j]]-=1

countingSort(A,B,max(A))
print(*B)

