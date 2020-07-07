#coding:UTF-8

def Max(A):
    max=0
    for i in range(len(A)):
        if A[i]>max:
            max=A[i]
    return max

def CS(A,n):
    B=[]
    C=[]
    cn=Max(A)+1
    for i in range(n):
        B.append(0)
    for i in range(cn):
        C.append(0)
    for j in range(n):
        C[A[j]]+=1
    for i in range(1,cn):
        C[i]+=C[i-1]
    for j in reversed(range(n)):
        B[C[A[j]]-1]=A[j]
        C[A[j]]-=1
    for i in range(len(B)):
        B[i]=str(B[i])
    print(" ".join(B))
 
    
if __name__=="__main__":
    n=int(input())
    A=input().split(" ")
    for i in range(n):
        A[i]=int(A[i])
    CS(A,n)
