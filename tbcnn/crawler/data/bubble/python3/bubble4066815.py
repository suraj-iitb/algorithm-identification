n=int(input())
a=list(map(int,input().split()))
flag = 1
b=0
while flag:
    flag = 0
    for i in range(n-1,0,-1):
        if a[i]<a[i-1]:
            tmp=a[i-1]
            a[i-1]=a[i]
            a[i]=tmp
            b+=1
            flag=1
a=" ".join(map(str,a))
print(a)
print(b)
