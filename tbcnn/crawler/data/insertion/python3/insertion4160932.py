#アルゴリズムの実装
def insertionSort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(" ".join(map(str, A)))

#入力dataの挿入
input_N = int(input())
input_A = list(map(int, input().split()))
print(" ".join(map(str, input_A)))

#処理の実行
insertionSort(input_A, input_N)

