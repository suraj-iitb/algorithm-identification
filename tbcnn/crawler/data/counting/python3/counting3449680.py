n =  int(input())
nums = list(map(int,input().split(" ")))

def countingSort(A,N):
    C = [0]*(max(A)+2)

    for i in range(N):
        C[A[i]] += 1

    for i in range(1,len(C)):
        C[i] = C[i] + C[i-1]


    B = [0]*N
    for i in range(n-1,-1,-1):
        B[C[A[i]]-1] = A[i]
        C[A[i]] -= 1

    return B

ans = countingSort(nums,n)
print(' '.join(map(str,ans)))

