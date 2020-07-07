
def swap(A, i, j):
    tmp = A[i]
    A[i] = A[j]
    A[j] = tmp



def bubble_sort(A, n):
    count = 0
    for i in range(0, n):
        for j in range(n-1, i, -1):
                if A[j] < A[j-1]:
                    swap(A, j, j-1)
                    count += 1
    return A, count

n = int(input())
A = [int(x) for x in input().split()]

s_A, count = bubble_sort(A, n)

print(" ".join([str(x) for x in s_A]))
print(count)
