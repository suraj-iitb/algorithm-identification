def bubbleSort(A, N):
    '''list of int, int -> list of int(sorted)
    N = len(A)
    return list(bubble sorted)
    '''
    assert(len(A) == N)
    outA = A.copy()
    flag = True
    numofcng = 0
    while flag:
        flag = False
        for j in range(N - 1, 0, -1):
            if outA[j] < outA[j - 1]:
                outA[j], outA[j - 1] = outA[j - 1], outA[j]
                numofcng += 1
                flag = True
    return outA, numofcng

def printlist(L):
    for itm in L[:-1]:
        print(itm, end = ' ')
    print(L[-1])

n = int(input())
A = list(map(int, input().split()))
outA, num = bubbleSort(A, n)
printlist(outA)
print(num)

