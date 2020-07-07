n=int(input())
a=list(map(int,input().split()))
flag=True
count=0
while flag:
    flag=False
    for i in range(1,n):
        if a[i]<a[i-1]:
            key=a[i]
            a[i]=a[i-1]
            a[i-1]=key
            count+=1
            flag=True
a=list(map(str,a))
print(' '.join(a))
print(count)
