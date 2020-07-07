N = int(input())
A = list(map(int, input().split()))


for i in range(N):
    if N == 1:
        print(A[0])
        break
    j = i

    while j > 0 and A[j] < A[j-1]:
        if A[j] > A[j-1]:

            break
        k = A[j]
        l = A[j-1]
        A[j-1] = k
        A[j] = l
        j -= 1

    S = str(A[0])
    for k in range(1,N-1):
        S += " " + str(A[k])

    S = S + " "+str(A[N-1])
    print(S)

