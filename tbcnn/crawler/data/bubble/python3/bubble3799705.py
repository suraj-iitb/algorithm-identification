n=int(input())
a=list(map(int,input().split()))
cnt=0
flag=1

for i in range(0,n-1):
    flag=0
    for j in reversed(range(i+1,n)):
        if a[j-1]>a[j]:
            ab=a[j-1]
            a[j-1]=a[j]
            a[j]=ab
            flag=1
            cnt+=1
def convert(list): 
    res=" ".join(map(str, list)) 
    return res   
print(convert(a))
print(cnt)
