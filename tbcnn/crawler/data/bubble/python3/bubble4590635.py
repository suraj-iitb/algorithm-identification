a=int(input())
b=list(map(int,input().split(" ")))

def bubbleSort(lst,N):
    flag=1
    i=0
    cnt=0
    while flag:
        flag=0
        for j in range(N-1,i,-1):
            if lst[j]<lst[j-1]:
                lst[j],lst[j-1]=lst[j-1],lst[j]
                cnt+=1
                flag=1
        i+=1
    return lst,cnt
ans=bubbleSort(b,a)
print(" ".join(list(map(str,ans[0]))),ans[1],sep="\n")
