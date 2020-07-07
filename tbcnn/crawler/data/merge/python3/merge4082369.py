count=0
def mg(S,left,right,mid):
    global count
    L=[]
    L=S[left:mid]
    L.append(9999999999)
    R=[]
    R=S[mid:right]
    R.append(9999999999)
    r=0
    l=0
    for i in range(left,right):
        count=count+1
        if L[l]<=R[r]:
            S[i]=L[l]
            l=l+1
        else:
            S[i]=R[r]
            r=r+1
def ms(S,left,right):
    if right>left+1:
        mid=(right+left)//2
        ms(S,left,mid)
        ms(S,mid,right)
        mg(S,left,right,mid)
n=int(input())
S=[]
S=input().split()
S=[int(u) for u in S]
ms(S,0,n)
for i in range(0,n-1):
    print(S[i],end=" ")
print(S[n-1])
print(count)
