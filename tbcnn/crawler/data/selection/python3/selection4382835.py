def selectionSort(A,N):
    c = 0
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if(i!=minj):
            t = A[i]
            A[i] = A[minj]
            A[minj] = t
            c+=1

    a = [str(i) for i in A]
    print(" ".join(a))
    print(c)

if __name__=="__main__":
    n = int(input())
    l = [int(x) for x in input().split()]
    selectionSort(l,n)
