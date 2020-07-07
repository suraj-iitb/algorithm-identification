def insert_sort(A, N):
    print(*A, sep=' ')
    for i in range(1, N):
        tmp = A[i]
        j = i-1
        while j>=0 and A[j]>tmp:
            A[j+1] = A[j]
            j -= 1
            A[j+1] = tmp
        print(*A, sep=' ')

N = int(input())
A = list(map(int, input().split()))

insert_sort(A, N)
