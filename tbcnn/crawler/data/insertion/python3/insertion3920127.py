

n=int(input())

l=[int(x) for x in input().split()]

for i in range(n):
    j=i
    while j>0 :
        if l[j-1]>l[j]:
            a=l[j]
            l[j]=l[j-1]
            l[j-1]=a
            j-=1
        else :
            break

    print(*l)

