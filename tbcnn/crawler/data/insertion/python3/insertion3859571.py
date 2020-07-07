N = int(input())
s = list(map(int, input().split()))
for k in range(N):
    if k>0:
        print(" ",sep='',end='')
    print(s[k],sep='',end='')
print()



def insertionSort(A,N):
    for i in range(1,N):
        v = A[i]
        j = i-1
        while j>=0 and A[j] > v:
            A[j+1] = A[j]
            j=j-1

        A[j+1]=v

        
        for k in range(N):
            if k>0:
                print(" ",sep='',end='')
            print(A[k],sep='',end='')

        print()

insertionSort(s,N)


