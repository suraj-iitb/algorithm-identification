def bubblesort(a,n,c):
    c=0
    flag=1
    while flag:
        flag=0
        for j in range(n-1,0,-1):
            if a[j]<a[j-1]:
                m=a[j]
                a[j]=a[j-1]
                a[j-1]=m
                flag=1
                c+=1
    return a,c

n=int(input())
a=list(map(int,input().split()))
c=0
ans=bubblesort(a,n,c)
a=ans[0]
c=ans[1]
print(" ".join(map(str,a)))
print(c)

