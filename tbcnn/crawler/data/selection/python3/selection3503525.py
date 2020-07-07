def selectionsort(l,n):
    c=0
    for i in range(n):
        minj=i
        for j in range(i,n):
            if int(l[j])<int(l[minj]):
               minj=j
        l[i],l[minj]=l[minj],l[i]
        if i!=minj:
          c+=1
    print(" ".join(l))
    print(c)
n=int(input())
l=list(input().split())
selectionsort(l,n)
