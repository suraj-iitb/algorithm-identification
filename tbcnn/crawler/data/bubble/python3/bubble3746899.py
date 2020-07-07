def bubble_sort(A):
    num = 0
    for i in range(len(A)):
        for j in range(len(A)-1, i, -1):
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                num += 1
                
    print(' '.join(list(map(str, A))))
    print(num)

n = input()
A = list(map(int, input().split()))
bubble_sort(A)
