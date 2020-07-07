def selectionSort(A,N):
    '''list of int, int -> list of int
    return sorted list(selection sort)
    '''
    assert(len(A) == N)
    outA = A.copy()
    cnt = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if outA[j] < outA[minj]:
                minj = j
        outA[i], outA[minj] = outA[minj], outA[i]
        if i != minj:
            cnt += 1
    return outA, cnt
def printlist(L):
    for itm in L[:-1]:
        print(itm, end = ' ')
    print(L[-1])

n = int(input())
A = list(map(int, input().split()))
A, num = selectionSort(A, n)
printlist(A)
print(num)

