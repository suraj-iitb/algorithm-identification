n=int(input())
z=list(map(int,input().split()))
flag=1
a=0
cnt=0
while flag:
    flag=0

    for i in reversed(range(a,n)):
        if i ==0:
            break
        if z[i]<z[i-1]:
            tmp=z[i]
            z[i]=z[i-1]
            z[i-1]=tmp
            flag=1
            cnt+=1
        
    a+=1
print(' '.join(list(map(str,z))))
print(cnt)
