def mergeArray(a,b,bLength,c,cLength):
    global count
    apos,bpos,cpos=(0,0,0)
    while bpos<bLength and cpos<cLength:
        if b[bpos]<=c[cpos]:
            a[apos]=b[bpos]
            bpos+=1
        else:
            a[apos]=c[cpos]
            cpos+=1
        apos+=1
        count+=1
    
    while bpos<bLength:
        a[apos]=b[bpos]
        apos+=1
        bpos+=1
        count+=1
    
    while cpos<cLength:
        a[apos]=c[cpos]
        apos+=1
        cpos+=1
        count+=1

def mergeSort(a,aLength):
    b=[]
    c=[]
    if aLength>=2:
        b=a[:aLength//2]
        c=a[aLength//2:]
        mergeSort(b,len(b))
        mergeSort(c,len(c))
    mergeArray(a,b,len(b),c,len(c))

count=0
aLength=int(input())
a=list(map(int,input().split()))
mergeSort(a,aLength)
print(*a)
print(count)
