N = int(input())
A = [int(i) for i in input().split()]
def printA():
    for i in range(0, N-1):
            print(A[i], '', end='')
    print(A[N-1])

for i in range(0,N):
    v = A[i]
    for j in range(i,-1,-1):
        if A[j-1] <= v or j == 0:
            A[j+1:i+1] = A[j:i]
            A[j] = v
            break
    printA()
