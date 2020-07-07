def insertionSort(A,N):
    print(*A)
    for i in range(1,N):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1],A[j] = A[j],A[j+1]
            # print(f'i={i} j={j}')
            j -= 1
        print(*A)


N = int(input())
A = list(map(int,input().split()))
insertionSort(A,N)
