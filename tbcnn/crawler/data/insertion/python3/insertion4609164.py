N = int(input())

nums = list(map(int, input().split()))

def insertionSort(A, N):
    for i in range(1, N):
        show(A)
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j = j-1

        A[j+1] = v

    show(A)

def show(lst):
    print(*lst)


insertionSort(nums, N)
