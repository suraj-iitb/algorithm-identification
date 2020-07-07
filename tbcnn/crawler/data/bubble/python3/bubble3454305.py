def bubble_sort(A, N):
    count = 0
    flag = True
    while flag:
        flag = False
        for i in range(N-1, 0, -1):
            if A[i] < A[i-1]:
                A[i-1], A[i] = A[i], A[i-1]
                count += 1
                flag = True
    return count


N = int(input())
A = list(map(int, input().split()))

count = bubble_sort(A, N)
print(" ".join(list(map(str, A))))
print(count)

