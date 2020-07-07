#coding:UTF-8
def SS(N,A):
    count=0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j]<A[minj]:
                minj=j
        if i!=minj:
            count+=1
            swap=A[i]
            A[i]=A[minj]
            A[minj]=swap
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
    SS(N,A)
