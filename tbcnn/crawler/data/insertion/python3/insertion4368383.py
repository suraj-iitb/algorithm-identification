def insertSort(a,n):
    L=[str(ai) for ai in a]
    L=" ".join(L)
    print(L)
    for i in range(1,n):
        v = a[i]
        j = i-1
        while(j>=0 and a[j]>v):
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v;
        L=[str(ai) for ai in a]
        L=" ".join(L)
        print(L)
        
n = int(input())
a = list(map(int,input().split()))
insertSort(a,n)
