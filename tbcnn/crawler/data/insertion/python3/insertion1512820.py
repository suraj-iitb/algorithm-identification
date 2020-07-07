def insertionSort(a,n):
    for i in range(n):
        print(a[i],end="")
        if(i!=n-1):
            print(" ",end="")
    print("")    
    for i in range(1,n):
        v=a[i]
        j=i-1
        while(j>=0 and a[j]>v):
            a[j+1] = a[j]
            j-=1
        a[j+1] = v
        for i in range(n):
            print(a[i],end="")
            if(i!=n-1):
                print(" ",end="")
        print("")

a=[]
n=int(input())
s=input()
a=list(map(int,s.split()))
insertionSort(a,n)
