"""
計数ソートを実装する
計算量はO(n+k)
"""
def countingSort(A, B, k):
    global n
    C = [0]*(k+1) #kは最大値

    for i in range(n):
        C[A[i]] += 1 #要素数を記録する
    
    for i in range(1, k+1):
        C[i] = C[i-1] + C[i]
    
    for i in range(n-1, -1, -1):
        C[A[i]] -= 1
        B[C[A[i]]] = A[i]
    
    
n = int(input())
a = list(map(int, input().split()))
b = [0] * n
k = max(a)

countingSort(a, b, k)
b = map(str, b)
print(' '.join(b))

