n = int(input())
A = list(map(int,input().split(" ")))


def fun(n,A):
    for i in range(n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j-=1
        A[j+1] = v
        print(" ".join(["{0["+ str(i) + "]}" for i in range(n)]).format(A))

fun(n,A)
