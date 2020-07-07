n = int(input())
a = list(map(int, input().split()))

def insertion_sort(a, n):
    print(" ".join(map(str, a)))
    for i in range(1, n):
        v = a[i]
        j = i - 1
        
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        
        print(" ".join(map(str, a)))

insertion_sort(a=a, n=n)


"""
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
"""
