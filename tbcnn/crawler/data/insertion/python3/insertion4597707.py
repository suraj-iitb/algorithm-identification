def show(a):
    ans=""
    for c in a:
        if c==a[-1]:
            ans+=str(c)
        else:    
            ans+=str(c)+" "
    print(ans)

def insertionsort(a,n):
    show(a)
    for i in range(1,n):
        v=a[i]
        j=i-1
        while j>=0 and a[j]>v:
            a[j+1]=a[j]
            j-=1
        a[j+1]=v
        show(a)

n=int(input())
line=list(map(int,input().split()))
insertionsort(line,n)
