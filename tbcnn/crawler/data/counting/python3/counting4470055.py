n = int(input())
sort_list = list(map(int,input().split()))

def countingsort(A, B ,k):
    C = [0 for i in range(k + 1)]
    B = [0 for i in range(len(A))]

    for j in range(len(A)):
        C[A[j]] += 1

    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]

    for j in range(n-1,-1,-1):
        c = C[A[j]] - 1
        B[c] = A[j]
        C[A[j]] -= 1

    return B

ans = []
ans = countingsort(sort_list,ans,max(sort_list))
print(' '.join([str(i) for i in ans]))

