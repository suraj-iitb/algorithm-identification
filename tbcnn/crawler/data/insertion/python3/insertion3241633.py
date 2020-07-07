N=int(input())
A=list(map(int,input().split()))

def hyouji(A):
    for z in range(len(A)):
        if z==0:
            print(A[z],end="")
        else:
            print(" "+str(A[z]),end="")
    print()

hyouji(A)
for i in range(1,N):
    v=A[i]
    j=i-1

    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j=j-1
    A[j+1]=v

    hyouji(A)

