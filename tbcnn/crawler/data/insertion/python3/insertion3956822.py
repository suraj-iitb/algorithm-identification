
N = int(input())
A = list(map(int, input().split()))

# A_sort = A
A_str = map(str, A)
print(" ".join(A_str))

for i in range(1, N, 1):
    # for j in range(i):
    #     if A[i] < A_sort[j]:
    #         A_sort[j+1] = 1
    v = A[i]
    j = i-1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j = j - 1
    A[j+1] = v

    A_str = map(str, A)
    print(" ".join(A_str))

