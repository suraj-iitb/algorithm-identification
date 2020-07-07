n=int(input())
l=list(map(int, input().split()))
l_res=sorted(l)
cnt=0
for i in reversed(range(n)):
    for j in range(i):
        if l[j]>l[j+1]:
            l[j],l[j+1]=l[j+1],l[j]
            cnt+=1
print(*l_res)
print(cnt)
