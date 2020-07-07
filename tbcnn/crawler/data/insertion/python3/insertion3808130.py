N=int(input())
A=list(map(int,input().split()))
for i in range(len(A)):
    val=A[i]
    j=i-1
    while (j>=0 and A[j]>val):
        A[j+1]=A[j]
        j=j-1
    A[j+1]=val

    string=[str(a) for a in A]
    out=' '.join(string)
    print(out)


