N=int(input())
A=list(map(int,input().split()))
def flag(A):
    j = 0
    for i in range(len(A)-1):
        if A[i] > A[i+1]:
            j = 1
    return j != 0 
n = 0
while flag(A):
    for i in range(N-1):
        if A[i] > A[i+1]:
            A_i = A[i]
            A[i] = A[i+1]
            A[i+1] = A_i
            n += 1
print(*A)
print(n)
