def bubble(A, N):
    c = 0
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                c += 1
                flag = True
    return A, c

if __name__ == "__main__":
    N = int(input())
    A = [int(i) for i in input().split()]

    A, c = bubble(A, N)
    print (*A)
    print (c)
