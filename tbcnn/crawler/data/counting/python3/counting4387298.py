k = 10**5
c = [0] * k
n = int(input())
A = [int(_) for _ in input().split()]
B = [0] * (n+1)
# print(B)

def CountingSort(A, B, k):
    for i in range(k):
        c[i] = 0

    for j in range(0, n):
        c[A[j]] += 1
        # print(A[j])
        # print(c)

    for i in range(1, k):
        c[i] = c[i] + c[i-1]

    # print(c)

    for j in range(n-1, -1, -1):
        # print(j)
        # print(A[j])
        # print(c[A[j]])
        B[c[A[j]]] = A[j]
        c[A[j]] -= 1

CountingSort(A, B, k)
print(" ".join(map(str, B[1:])))

