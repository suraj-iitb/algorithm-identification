def CountingSort(A, k):
    B = [0]*(len(A)+1)
    C = [0]*(k+1)
    for i in A:C[i]+=1
    for i in range(1,k+1):C[i]=C[i]+C[i-1]
    for i in range(n-1,-1,-1):
        B[C[A[i]]]=A[i]
        C[A[i]]-=1
    return B[1:]
n = int(input())
A = [int(i) for i in input().split()]
B = CountingSort(A,10000)
ans = ""
for i in B:ans+=str(i)+" "
print(ans[:-1])
