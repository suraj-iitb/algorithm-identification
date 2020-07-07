def insertionSort(A, N):
    for i in range(1, N):
        print(*A, sep=" ")
        
        v = A[i]
        j = i - 1

        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1

        A[j+1] = v

    print(*A, sep=" ")

    return A



N = int(input())

list_num = list(map(int, input().split()))

insertionSort(list_num, N)

