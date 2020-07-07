# Counting Sort

N = int(input())
lst = list(map(int, input().split()))
k = max(lst)
B = [-1]*N
C = [0] * (k+1)

def counting_sort(A, B, k):
    # 出現回数をカウント
    for a in A:
        C[a] += 1
    # 累積和を作成
    for i in range(1, k+1):
        C[i] = C[i] + C[i-1]
    for a in A[::-1]:
        C[a] -= 1
        B[C[a]] = a
        
counting_sort(lst, B, k)
print(*B)
        
