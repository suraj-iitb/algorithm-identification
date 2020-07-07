def bubbleSort(A: list, N:int) -> list:
    """
    A[N]	サイズがNの整数型配列。
    i	未ソートの部分の先頭を指すループ変数で、配列の先頭から末尾に向かって移動します。
    j	未ソートの部分の隣り合う要素を比較するためのループ変数で、Aの末尾であるN-1 から開始しi+1 まで減少します。
    """
    has_finished = True
    i = 0
    count = 0
    while has_finished and len(A) > 1:
        has_finished = False
        for j in reversed(range(i + 1, N)):
            if A[j] < A[j - 1]:
                # alter position
                a, b = A[j - 1], A[j]
                A[j - 1], A[j] = b, a
                has_finished = True
                count += 1
        i += 1
    return A, count

    
N = int(input())
A = list(map(int, input().split()))
A, count = bubbleSort(A, N)

print(*A)
print(count)

