def print_list(num_list):
    print(" ".join(map(str, num_list)))

N = int(input())

A = list(map(int, input().split()))

print_list(A)

for i in range(1, N):
    v = A[i]
    j = i - 1
    while j >=0 and v < A[j]:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v
    print_list(A)

