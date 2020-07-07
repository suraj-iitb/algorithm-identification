n=int(input())
l=list(map(int,input().split()))
print(" ".join(list(map(str,l))))
for i in range(1,n):
    x=l[i]
    for j in range(0,i)[::-1]:
        if(l[j] <= x):
            j+=1
            break
    del l[i]
    l.insert(j,x)
    print(" ".join(list(map(str,l))))
