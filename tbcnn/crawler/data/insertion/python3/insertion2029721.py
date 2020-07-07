#coding:UTF-8
def IS(N,A):
    for i in range(int(N)):
        v=A[i]
        j=i-1
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j=j-1
        A[j+1]=v
        ans=""
        for k in range(len(A)):
            ans+=str(A[k])+" "
        print(ans[:-1])

if __name__=="__main__":
    N=input()
    a=input()
    A=a.split(" ")
    for i in range(len(A)):
        A[i]=int(A[i])
    IS(N,A)
