from sys import stdin

def countingSorted(A):
    VALUE_MAX = max(A)
    B = [0] * (len(A)+1)
    C = [0] * (VALUE_MAX+1)

    for A_i in A:
        C[A_i] += 1

    for i in range(1, VALUE_MAX+1):
        C[i] += C[i-1]

    for A_i in reversed(A):
        B[C[A_i]] = A_i
        C[A_i] -= 1

    return B[1:]

n = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
print(*countingSorted(A))

