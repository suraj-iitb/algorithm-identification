import sys

INF = 10**9

N = int(sys.stdin.readline())
A = [int(x) for x in sys.stdin.readline().split()]

z = 0


def merge(A, left, right):

    global z

    n1 = (right - left) // 2 + left  # L側の個数

    # L[0...n1], R[0...n2] を生成
    # L = A[left:n1].copy()
    # R = A[n1:right].copy()

    L = A[left:n1]
    R = A[n1:right]


    L.append(INF)
    R.append(INF)

    # print(L, R)

    i = 0
    j = 0
    for k in range(left, right):
        z += 1 

        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1


def mergesort(A, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergesort(A, left, mid)
        mergesort(A, mid, right)
        merge(A, left, right)


mergesort(A, 0, N)

print(" ".join([str(x) for x in A]))
print(z)
