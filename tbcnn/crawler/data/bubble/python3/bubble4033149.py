def bubble_sort(A, N):
    flag = True
    swap_count = 0
    while flag:
        flag = False
        for j in range(1, N)[::-1]:
            if A[j] < A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                swap_count += 1
                flag = True
    return A, swap_count
N = int(input())
A = list(map(int, input().split(' ')))
sorted_A, swap_count = bubble_sort(A, N)
print(" ".join(map(str, sorted_A)))
print(swap_count)
