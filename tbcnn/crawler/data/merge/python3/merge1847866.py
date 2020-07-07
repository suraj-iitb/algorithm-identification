cnt = 0
def merge(L,R):
    global cnt
    n = len(L)+len(R)
    cnt += n
    A = []
    i = j = 0
    L.append(-1)
    R.append(-1)
    for _ in range(n):
        if L[i] >= R[j]:
            A.append(L[i])
            i += 1
        else:
            A.append(R[j])
            j += 1
    return A

def mergeSort(A):
    if len(A)==1: return A
    m = len(A)//2
    return merge(mergeSort(A[:m]),mergeSort(A[m:])) 
    

if __name__=='__main__':
    n=int(input()) 
    A=list(map(int,input().split()))
    print(*mergeSort(A)[::-1])
    print(cnt)
