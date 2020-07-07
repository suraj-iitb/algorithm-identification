def CountingSort(A,B,k):
    n=len(A)
    C=[0]*(k+1)
    for i in range(n):
        C[A[i]] +=1
    for i in range(1,k+1):
        C[i]=C[i-1]+C[i]
    for i in reversed(range(n)):
        B[C[A[i]]-1]=A[i]
        C[A[i]] -=1


n=int(input())
A=list(map(int,input().split()))
B=[0]*n
CountingSort(A,B,10000)
print(*B)
