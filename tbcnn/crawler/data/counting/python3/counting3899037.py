N = int(input())
A = [int(x) for x in input().split()]

def CountingSort(A,k):
    C = [0 for x in range(k+1)]
    B = [0 for x in range(N)]

    for j in range(N):
        C[A[j]] += 1

    for i in range(k):
        C[i+1] += C[i]

    for j in reversed(range(N)):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1

    return B

B = CountingSort(A,max(A))

for i in range(N):
    if i != N-1:
        print(B[i], end=" ")
    elif i == N-1:
        print(B[N-1])

