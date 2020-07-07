def countingSort(A,k):
    C = {}
    for ai in A:
        C[ai] = C.get(ai,0) + 1
    for i in range(1,k+1):
        C[i] = C.get(i,0) + C.get(i-1,0)
    B = A[:]
    for ai in A:
        B[C[ai]-1] = ai
        C[ai] -= 1
    return B

if __name__=='__main__':
    n=int(input())
    print(*countingSort(list(map(int,input().split())),10000))
