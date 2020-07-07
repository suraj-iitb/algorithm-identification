def csort(A,B,k):
    C=[0]*(k+1)
    for i in range(len(A)):
        C[A[i]]+=1
    for i in range(1,len(C)):
        C[i]+=C[i-1]
    for i in range(len(A))[::-1]:
        B[C[A[i]]-1]=A[i]
        C[A[i]]-=1
        
# input
n=int(input())
data=list(map(int, input().split()))
result=[0]*len(data)
csort(data,result,10000)
print(*result)
