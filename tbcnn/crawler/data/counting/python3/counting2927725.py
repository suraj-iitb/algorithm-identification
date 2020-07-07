def counting_sort(A, B, k):
    C = {i: 0 for i in range(k+1)}

    for j in A:
        C[j] += 1

    for i in range(1, k+1):
        C[i] += C[i-1]

    for j in A[::-1]:
        B[C[j]-1] = j
        C[j] -= 1

def print_list(B):
    for i, j in enumerate(B):
        if i == n - 1:
            print(j)
        else:
            print(j, end=" ")

n = int(input())
A = [int(e) for e in input().split()]
B = [0 for i in range(n)]
counting_sort(A, B, max(A))
print_list(B)

