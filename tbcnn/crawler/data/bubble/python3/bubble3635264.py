n=int(input())
l=list(map(int,input().split()))
flg=True
counter=0
while flg:
    flg=False
    for j in reversed(range(1,n)):
        if l[j]<l[j-1]:
            l[j],l[j-1]=l[j-1],l[j]
            flg=True
            counter+=1
for i in range(n):
    if i!=n-1:
        print(l[i],end=' ')
    else:
        print(l[i])
print(counter)
