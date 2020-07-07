def insertionSort(A,N):
    for i in range(1,N):
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j-=1
        A[j+1]=v
        print(str(A).replace(",",'').replace("[",'').replace("]",''))


N=int(input())
sl=input()
print(sl)
lis=list(map(int,sl.split()))
insertionSort(lis,N)
