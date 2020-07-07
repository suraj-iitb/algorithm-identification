n=int(input())
A=list(map(int,input().split()))
def convert(list):
    s=[str(i) for i in list]
    res = " ".join(s)
    return res
print(convert(A))
for i in range(1,n):
    v=A[i]
    j=i-1
    while j>=0 and A[j]>v:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    print(convert(A))
