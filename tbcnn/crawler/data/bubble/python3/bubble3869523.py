n=int(input())
s=list(map(int,input().split()))
swap=0

def bubble_sort(A,N,swap):
    flag=True
    while flag:
        flag=False
        for j in range(N-1,0,-1):
            if A[j]<A[j-1]:
                temp=A[j]
                A[j]=A[j-1]
                A[j-1]=temp
                swap+=1
                flag=True
    return A,swap

Rst,swap=bubble_sort(s,n,swap)

print(Rst[0],end='',sep='')
for i in range(1,n):
    print(" ",Rst[i],end='',sep='')
print()
print(swap)

