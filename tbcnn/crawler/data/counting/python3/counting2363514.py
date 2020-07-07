# coding=utf-8

def counting_sort(A, B, k):
    C = [0 for i in range(k+1)]

    for a in A:
        C[a] += 1

    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]

    for a in A[::-1]:
        B[C[a]-1] = a
        C[a] -= 1

    return B


n = int(input())
A = list(map(int, input().split()))
k = max(A)
B = [0 for x in range(n)]

B = counting_sort(A, B, k)
print(*B)
