n=int(input())
l=list(map(int, input().split()))
cnt=0
for i in range(n):
    if n==1:
        break
    elif l[i]!=min(l[i:n]):
        num=l[i:n].index(min(l[i:n]))+i
        l[i],l[num]=l[num],l[i]
        cnt+=1
print(*l)
print(cnt)
