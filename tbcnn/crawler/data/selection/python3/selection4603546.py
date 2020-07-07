n=int(input())
num_list=list(map(int,input().split()))

count=0
for i in range(0,len(num_list)):
    minj=i
    for j in range(i+1,len(num_list)):
        if num_list[minj]>num_list[j]:
            minj=j
    tmp=num_list[minj]
    num_list[minj]=num_list[i]
    num_list[i]=tmp
    if minj!=i:
        count+=1

ans=str(num_list[0])
for i in range(1,len(num_list)):
    ans+=" "+str(num_list[i])
print(ans)
print(count)

