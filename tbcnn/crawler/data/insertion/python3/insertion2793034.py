def insertionSort(a,n):
    for i in range(1,n):
        for k in range(n):
            print(a[k],end='')
            if k==n-1:
                print()
            else:
                print(' ',end='')

        v=a[i]
        j=i-1
        while j>=0 and a[j]>v:
            a[j+1]=a[j]
            a[j]=v
            j-=1
    for k in range(n):
        print(a[k],end='')
        if k==n-1:
            print()
        else:
            print(' ',end='')

n=int(input())
r=input()
data=r.split(' ')
for i in range(n):
    data[i]=int(data[i])
insertionSort(data,n)
