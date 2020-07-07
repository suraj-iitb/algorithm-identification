#coding:UTF-8
def BS(N,A):
    count=0
    flag=True
    while flag==True:
        flag=False
        for i in range(1,N):
            if A[N-i]<A[N-i-1]:
                swap=A[N-i]
                A[N-i]=A[N-i-1]
                A[N-i-1]=swap
                flag=True
                count+=1
    for i in range(len(A)):
        A[i]=str(A[i])
    print(" ".join(A))
    print(count)

if __name__=="__main__":
    N=int(input())
    a=input()
    A=a.split(" ")
    for i in range(len(A)):
        A[i]=int(A[i])
    BS(N,A)
