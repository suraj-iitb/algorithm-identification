n=int(input())

list=list(map(int,input().split()))
for i2 in range(len(list)):
    if i2!=len(list)-1:
        print(list[i2],end=' ')
    else :
        print(list[i2])

for i in range(1,n):
    v=list[i]
    j=i-1
    while j>=0 and list[j]>v:
        list[j+1]=list[j]
        j=j-1
    list[j+1]=v
    for i2 in range(len(list)):
        if i2!=len(list)-1:
            print(list[i2],end=' ')
        else :
            print(list[i2])

