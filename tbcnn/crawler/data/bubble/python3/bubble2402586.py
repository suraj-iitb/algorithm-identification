N = int(input())
A = list(map(int, input().split(" ")))

def print_list(A):
    for a in A[:-1]:
        print ("%d "%a, end="")
    print(A[-1])

def BubbleSort(A, N):
    count = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                v = A[j]
                A[j] = A[j-1]
                A[j-1] = v
                count += 1
                flag = True
                
    return A, count

A_sorted, c = BubbleSort(A, N)

print_list(A_sorted)
print(c)
