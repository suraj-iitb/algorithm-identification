N = int(input().rstrip())
A = list(map(int, input().rstrip().split()))

def bubble_sort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                count += 1
                flag = 1
    return A, count


A, count = bubble_sort(A, N)
string = list(map(str, A))
print(' '.join(string))
print(count)

