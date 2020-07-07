def insertionSort(A, N):
    '''list of int, int(=len(A)) -> list of int
    return sorted list(insertion sort)
    '''
    l = N
    outA = A.copy()
    for i in range(l):
        val = outA[i]
        j = i - 1
        while j >= 0 and outA[j] > val:
            outA[j + 1] = outA[j]
            j -= 1
        outA[j + 1] = val
        printlist(outA)
    return outA
def printlist(L):
    '''
    print list with space
    '''
    for item in L[:-1]:
        print(item, end = ' ')
    print(L[-1])

n = int(input())
A = list(map(int,input().split()))
_ = insertionSort(A, n)

