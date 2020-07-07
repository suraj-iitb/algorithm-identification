N=int(input())
arr=list(map(int,input().split()))
print(' '.join(map(str,arr)))
for key in range(1,len(arr)):
    temp=arr[key]
    i=key-1
    while i>=0 and arr[i]>temp:
        arr[i+1]=arr[i]
        i-=1
    arr[i+1]=temp
    print(' '.join(map(str,arr)))
