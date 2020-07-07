#ALDS1_2-A Bubble Sort
def bubbleSort(A,N):
    c=0
    flag=1
    while flag:
        flag=0
        j=N-1
        while j>0:
            if(int(A[j])<int(A[j-1])):
                c+=1
                A[j],A[j-1]=A[j-1],A[j]
                flag=1
            j-=1
    return c

N=int(input())
A=input().split()
c=bubbleSort(A,N)
S=""
for i in range(N-1):
    S+=A[i]+" "
S+=str(A[-1])
print(S)
print(c)
