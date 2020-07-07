x=int(input())


a=list(map(int,input().split()))
for k in range(x-1):
    print(a[k],end=' ')
print(a[x-1])


for i in range(1,x):
    j=i-1
    b=a[i]
    
    while j >= 0 and a[j] > b:
        a[j+1]=a[j]
        j=j-1
   
        
    a[j+1]=b
    for k in range(x-1):
        print(a[k],end=' ')
    print(a[x-1])




