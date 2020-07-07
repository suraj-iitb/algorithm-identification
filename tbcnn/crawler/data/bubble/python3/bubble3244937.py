n=int(input())
lst=list(map(int,input().split()))
count=0
for i in range(n-1):
    for j in range(1+i,n)[::-1]:
        if lst[j-1]>lst[j]:
            count+=1
            lst[j-1],lst[j]=lst[j],lst[j-1]
print(*lst)
print(count)
