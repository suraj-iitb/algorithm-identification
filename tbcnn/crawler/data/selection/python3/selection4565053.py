
# 出題: プロコンのためのアルゴリズムとデータ構造 3.4

def printList(array):
    print(' '.join(map(str, array)))

# N個の要素を持つ配列A

def selectionSort(A, N):
    swapCount = 0
    for index in range(0, N):
        minj = index
        for j in range(index, N):
            if A[j] < A[minj]:
                minj = j

        if index != minj:
            swapCount += 1

        A[index], A[minj] = A[minj], A[index]

    printList(A)
    print(str(swapCount))


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    selectionSort(A, N)

