N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    v = A[i]
    if v >= A[0]:
        j = 0
        while v >= A[j] and j < i:
            j = j + 1
        if j < i:
            for k in reversed(range(j, i)):
                A[k + 1] = A[k]
            A[j] = v
            print(' '.join([str(a) for a in A]))
        else:
            print(' '.join([str(a) for a in A]))

    else:
        for l in reversed(range(i)):
            A[l+1]=A[l]
        A[0]=v
        print(' '.join([str(a) for a in A]))


