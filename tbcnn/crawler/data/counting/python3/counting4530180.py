import sys

def CountingSort(A,B,k):
    C = [0]*(10001)
    for i in range(n):
        C[A[i+1]] += 1
    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]
    for i in range(1,n+1):
        B[C[A[i]]] = A[i]
        C[A[i]]-=1

if __name__ == "__main__":
    n = int(input())
    A = [0] + list(map(int,input().split()))
    k = 10000
    B = [0]*(n+1)
    CountingSort(A,B,k)
    print(*B[1:])


