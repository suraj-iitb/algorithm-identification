n=int(input())
A=list(map(int,input().split()))
counter=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if A[j] < A[minj]:
            minj=j
    if i!=minj:
        tmp=A[i]
        A[i]=A[minj]
        A[minj]=tmp
        counter+=1
for k in range(len(A)):
    if k != len(A)-1:
        print(A[k],end=' ')
    else:
        print(A[k])
print(counter)
