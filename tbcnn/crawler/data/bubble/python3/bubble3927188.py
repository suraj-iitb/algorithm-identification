n=int(input())
a=list(map(int,input().split()))
s=0

for i in range(len(a)):
    for j in reversed(range(1,n)):
        if a[j]<a[j-1]:
            a[j-1],a[j]=a[j],a[j-1]
            s+=1
for i in range(n):
    if i==0:
        print(a[i],end="")
    else:
        print("{: }".format(a[i]),end="")
print()
print(s)

