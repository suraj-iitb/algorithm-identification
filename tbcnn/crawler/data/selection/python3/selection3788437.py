def selectionsort(a,n):
    count=0
    for i in range(n):
        minj=i
        for j in range(i,n):
            if a[j]<a[minj]:
                minj=j
        if i!=minj:
            m=a[i]
            a[i]=a[minj]
            a[minj]=m
            count+=1
    return a,count

n=int(input())
a=list(map(int,input().split()))
ans=selectionsort(a,n)
print(" ".join(map(str,ans[0])))
print(ans[1])

