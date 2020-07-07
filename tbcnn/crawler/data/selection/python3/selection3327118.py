def selectionSort(A, N): # N個の要素を含む0-オリジンの配列A
    counter = 0
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            counter += 1
    return A, counter

if __name__ == '__main__':
    N = int(input())
    a = list(map(int, input().split()))
    a, num = selectionSort(a, N)
    for i in range(len(a)):
        if i != len(a)-1:
            print(a[i], end=" ")
        else:
            print(a[i])
    print(num)

