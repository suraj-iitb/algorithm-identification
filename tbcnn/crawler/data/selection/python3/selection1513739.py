def selection_sort(a,n):
    m=0
    for i in range(0,n):
        minj=i
        for j in range(i,n):
            if(a[minj] > a[j]):
                minj=j
        if(minj!=i):
            m+=1
            #print("swap(%d<->%d)"%(a[ninj],a[i]))
            a[minj],a[i] = a[i],a[minj]
        
    b=list(map(str,a))
    print(" ".join(b))
    print(m)

a=[]
n=int(input())
s=input()
a=list(map(int,s.split()))
selection_sort(a,n)
