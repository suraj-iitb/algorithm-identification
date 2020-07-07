def countingSort(A):
    VMAX = 10**4 # A[i] の取りうる範囲
    C = [0] * VMAX
    result = [None] * (len(A))

    # C に A の各要素の出現回数を記録
    for i in range(len(A)):
        C[A[i]] += 1

    # C に A の各要素以下の出現回数を記録 (累積)
    for i in range(1, VMAX):
        C[i] += C[i-1]

    for i in range(len(A)-1, -1, -1): # A の添字を後ろからたどる
        result[C[A[i]]-1] = A [i]
        C[A[i]] -= 1

    return result

n = int(input())
A = [i for i in map(int, input().split())]
result = countingSort(A)
result = [i for i in map(str, result)]
print(' '.join(result))
