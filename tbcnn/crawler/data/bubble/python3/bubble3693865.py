N=int(input())
A=list(map(int,input().split()))

c=0
for i in range(len(A)):
    for j in range(1,len(A)):
        if A[j] < A[j-1]:
            temp=A[j-1]
            A[j-1]=A[j]
            A[j]=temp
            c+=1
print(*A)
print(c)


