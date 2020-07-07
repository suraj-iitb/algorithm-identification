def countingSort(A, B, k):
    C = [0 for i in range(k+1)]

    for i in A:
        C[i] += 1

    for i in range(1, k+1):
        C[i] += C[i-1]

    for i in A[::-1]:
        B[C[i]-1] = i
        C[i] -= 1

    return B


n = int(input())
A = list(map(int, input().split()))
k = max(A)
B = [0 for x in range(n)]
B = countingSort(A, B, k)
print(*B)

