# ALDS1_6_A
def countingSort(a):
    j = max(a)
    c = [0 for _ in range(j + 1)]
    b = [None for _ in range(n)]
    for k in a: # 出現数を記録
        c[k] += 1
    for k in range(1, j+1): # bにおけるインデックスを記録
        c[k] += c[k - 1]
    for k in a[::-1]: # 逆順により安定なソート
        c[k] -= 1
        b[c[k]] = k
    return b

n = int(input())
a = list(map(int, input().split()))
print(*countingSort(a))
