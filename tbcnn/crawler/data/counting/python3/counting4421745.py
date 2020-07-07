N=int(input())
num_list=[int(i) for i in input().split()]
B=[None]*N
def counting(A,B,k):
    C = [0] * k
    for j in range(N):
        C[A[j]]+=1
    for i in range(1,k):
        C[i]+=C[i-1]
    for j in range(N-1,-1,-1):
        B[C[A[j]]-1]=A[j]
        C[A[j]]-=1
    return B
ans=counting(num_list,B,10000)
print(*ans)
