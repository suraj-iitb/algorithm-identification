N=int(input())
A=list(map(int,input().split()))
def bubbleSort(A,N):
    flg=1
    global ct
    ct = 0
    while flg:
        flg = 0
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                A[j-1],A[j]=A[j],A[j-1]
                flg=1
                ct+=1

    return ' '.join(map(str,A))

print(bubbleSort(A,N))
print(ct)
