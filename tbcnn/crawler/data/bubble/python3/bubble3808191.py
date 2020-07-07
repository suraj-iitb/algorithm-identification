N=int(input())
A=list(map(int,input().split()))
flag=True
count=0
while flag:
    flag=False
    for j in range(N-1, 0, -1):
        if A[j] < A[j-1]:
            tmp=A[j]
            A[j]=A[j-1]
            A[j-1]=tmp
            flag=True
            count=count+1

print(' '.join([str(a) for a in A]))
print("{}".format(count))


