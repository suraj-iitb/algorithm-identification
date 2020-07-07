
N = int(input())

A = list(map(int,input().split()))


for i in range(N-1):

    print (" ".join(map(str,A)))

    i += 1
    v = A[i]

    j = i - 1

    while j >= 0 and A[j] > v:

        A[j+1] = A[j]
        j -= 1

    A[j+1] = v


print (" ".join(map(str,A)))

