def CountingSort(A, B, k):
    global n
    C = [0]*(k+1)
    for num in A:
        C[num] += 1
    for i in range(1,k+1):
        C[i] = C[i] + C[i-1]
    for j in range(n,0,-1):
        B[C[A[j-1]]-1] = A[j-1]
        C[A[j-1]] -= 1

n = int(input())
A = list(map(int, input().split()))
B = [-1]*n
CountingSort(A, B, max(A))
print(*B)
