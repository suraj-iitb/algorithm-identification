'''
????????§????¢?????????????
???????????????????????????????????£????????????
???????????????????????????????????????????????????????????????
?????¢????????????????????????????????????????¢????????????°?????????
???????????????1?????§????????¢??????????????°???????????¨?????????
'''
def partition(A,p,r):
    x = A[r]
    i = p-1
    for j in range(p,r):
        if A[j][1] <= x[1]:
            i = i+1
            (A[i],A[j]) = (A[j],A[i])
    (A[i+1],A[r]) = (A[r],A[i+1])
    return i+1
 
def quicksort(A,p,r):
    if p < r:
        q = partition(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)

def isStable(A,n):
    for i in range(1,n-1):
        if A[i-1][1] == A[i][1] and A[i-1][2] > A[i][2]:
            return False
    return True

if __name__ == '__main__':
    n = (int)(input())
    A = []
    for i in range(0,n):
        tmp = list(input().split())
        A.append((tmp[0],(int)(tmp[1]),i))
    quicksort(A,0,n-1)

    print("Stable" if isStable(A,n) else "Not stable" )

    for x in A:
        print(x[0],x[1])
