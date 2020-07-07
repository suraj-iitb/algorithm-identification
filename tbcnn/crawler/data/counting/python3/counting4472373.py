MAX =20000001
VMAX = 10001
INF = 10 ** 10
cnt = 0

def CountingSort(A, n):
    B = [0 for x in range(n)]
    C = [0 for x in range(VMAX)]
    # C[i] に i の出現数を記録する
    for j in range(n):
        C[A[j]] += 1

     #  C[i] に i 以下の数の出現数を記録する
    for i in range(VMAX):
        C[i] = C[i] + C[i-1]

    for j in range(n):
        B[C[A[j]] -1] = A[j] 
        C[A[j]] -= 1
    print(*B)


n = int(input())
A =[int(x) for x in input().split()]
CountingSort(A, n)
