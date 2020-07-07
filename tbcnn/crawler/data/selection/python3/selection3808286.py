N=int(input())
A=list(map(int,input().split()))
count=0
for i in range(N):
    minj=i
    for j in range(i+1, N):
        if(A[j] <  A[minj]):
            minj=j

    if(minj !=i):
        tmp=A[i]
        A[i]=A[minj]
        A[minj]=tmp
        count=count+1

print(' '.join([str(a) for a in A]))
print("{}".format(count))

