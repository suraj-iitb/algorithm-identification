#1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
#2   for i が 1 から N-1 まで
#3     v = A[i]
#4     j = i - 1
#5     while j >= 0 かつ A[j] > v
#6       A[j+1] = A[j]
#7       j--
#8     A[j+1] = v
def insertionSort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j-=1
        A[j+1] = v
        print(*A)

N = int(input())
A = list(map(int, input().split()))
print(*A)
insertionSort(A, N)

