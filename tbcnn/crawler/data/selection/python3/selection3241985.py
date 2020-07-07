n=int(input())
a=list(map(int,input().split()))
change=0

def hyouji(a,change):
    for i in range(len(a)):
        if i==0:
            print(a[i],end="")
        else:
            print(" "+str(a[i]),end="")
    print()
    print(change)


for i in range(n):
    mini=i
    for j in range(i,n):
        if a[j]<a[mini]:
            mini=j
    v=a[i]
    a[i]=a[mini]
    a[mini]=v
    if i!=mini:
        change+=1

hyouji(a,change)

