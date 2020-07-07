n=int(input())
a=list(map(lambda x:int(x),input().split()))
flag=True
number=0
while flag:
    flag=False
    for j in range(n-1,0,-1):
        if a[j]<a[j-1]:
            a[j],a[j-1]=a[j-1],a[j]
            number=number+1
            flag=True

for k in range(n-1):
    print(a[k],end=" ")
print(a[n-1])
print(number)



