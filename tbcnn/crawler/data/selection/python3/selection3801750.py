n=int(input())
a=list(map(int,input().split()))

cnt=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if a[j]<a[minj]:
            minj=j
            
    if minj!=i:
        ab=a[i]
        a[i]=a[minj]
        a[minj]=ab
        cnt+=1

def convert(list):
    res=" ".join(map(str, list))
    return res
print(convert(a))
print(cnt)
