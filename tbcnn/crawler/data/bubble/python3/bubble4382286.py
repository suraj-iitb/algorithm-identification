def bubble(A,N):
    flag = 1
    c = 0
    while flag:
        flag = 0
        for j in range(1,N)[::-1]:
            if A[j]<A[j-1]:
                t = A[j]
                A[j]=A[j-1]
                A[j-1]=t
                c+=1
                flag = 1
    
    L = [str(a) for a in A]
    print(" ".join(L))
    print(c)

if __name__=="__main__":
    n=int(input())
    l=[int(x) for x in input().split()]
    bubble(l,n)
