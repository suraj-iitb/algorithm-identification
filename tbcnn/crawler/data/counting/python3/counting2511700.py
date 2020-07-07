def CountingSort(A):
    B = [0]*len(A)
    maxnumber = 0
    for n in range(len(A)):
        if maxnumber < A[n]:
            maxnumber = A[n]
    C = [0]*(maxnumber + 1)

    for j in range(len(A)):
        C[A[j]] += 1
    for r in range(1, maxnumber+1):
        C[r] = C[r] + C[r-1]

    for s in range(len(A))[::-1]:
        B[C[A[s]]-1] =A[s]
        C[A[s]] -= 1

    return B


if __name__ == '__main__':
    cnt = input()
    A = list(map(int,input().split()))
    Ans = list(map(str,CountingSort(A)))
    print(" ".join(Ans))
