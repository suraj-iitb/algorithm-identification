def bubble_sort(A):
    count = 0
    for i in range(len(A)):
        for j in range(len(A)-1):
            if A[j+1] < A[j]:
                A[j+1], A[j] = A[j], A[j+1]
                count += 1
    return count

n = int(input())
A = list(map(int, input().split()))
count = bubble_sort(A)
print(*A)
print(count)
