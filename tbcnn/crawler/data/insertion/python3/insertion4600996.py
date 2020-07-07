n=int(input())
num_list=list(map(int,input().split()))

ans=str(num_list[0])
for k in range(1,len(num_list)):
    ans+=" "+str(num_list[k])
print(ans)

for i in range(1,n):
    v=num_list[i]
    j=i-1
    while j>=0 and num_list[j]>v:
        num_list[j+1]=num_list[j]
        j-=1
    num_list[j+1]=v

    ans=str(num_list[0])
    for k in range(1,len(num_list)):
        ans+=" "+str(num_list[k])
    print(ans)
