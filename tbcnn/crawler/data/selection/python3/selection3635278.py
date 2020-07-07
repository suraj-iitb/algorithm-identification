n=int(input())
l=list(map(int,input().split()))
counter=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if l[j]<l[minj]:
            minj=j
    if i !=minj:
        l[i],l[minj]=l[minj],l[i]
        counter+=1
for i in range(n):
    if i!=n-1:
        print(l[i],end=' ')
    else:
        print(l[i])
print(counter)
