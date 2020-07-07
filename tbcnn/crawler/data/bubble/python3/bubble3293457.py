N = int(input())
A = list(map(int, input().split()))

def bubbleSort(A, N):
    count = 0
    flag = 1
    while flag:
        flag = 0
        j = N - 1
        while j > 0:
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                count += 1
                flag = 1
            j -= 1
    return count


c = bubbleSort(A, N)
for i in range(len(A)):
    if i != len(A) - 1:
        print(A[i], end=" ")
    else:
        print(A[i])
print(c)

