n=int(input())
num_list=list(map(int,input().split()))

flag=1
count=0
while flag:
    flag=0
    for j in range(n-1,0,-1):
        if num_list[j]<num_list[j-1]:
            tmp=num_list[j]
            num_list[j]=num_list[j-1]
            num_list[j-1]=tmp
            count+=1
            flag=1

ans=str(num_list[0])
for i in range(1,len(num_list)):
    ans+=" "+str(num_list[i])
print(ans)
print(count)

