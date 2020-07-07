def bubble_sort(a,n):
    m=0
    flag=True
    while(flag):
        flag=False
        for i in range(n-1,0,-1):
            if(a[i-1] > a[i]):
                tmp=a[i-1]
                a[i-1]=a[i]
                m+=1
                a[i]=tmp
                flag=True
                
    b=list(map(str,a))
    print(" ".join(b))
    print(m)

a=[]
n=int(input())
s=input()
a=list(map(int,s.split()))
bubble_sort(a,n)
