n=int(input())
A=list(map(int,input().split()))
flag=1
counter=0
while flag:
    flag=0
    for j in range(1,n):
        if A[j] < A[j-1]:
            tmp=A[j]
            A[j]=A[j-1]
            A[j-1]=tmp
            flag=1
            counter+=1
for k in range(len(A)):
    if k != len(A)-1:
        print(A[k],end=' ')
    else:
        print(A[k])
print(counter)
