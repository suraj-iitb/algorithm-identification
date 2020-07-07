N = int(input())
A = list(map(int, input().split()))

def insec_sort(A, N):

    for i in range(1, N):
        print(*A)
        v = A[i]
        j = i - 1

        while j >= 0 and A[j] > v:
           A[j + 1] = A[j]
           j -= 1

        A[j + 1] = v
    print(*A)


insec_sort(A,N)


