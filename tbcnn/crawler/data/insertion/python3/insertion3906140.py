def insertion_sort(Array,num):
    for i in range(1,num):
        v=Array[i]
        j=i-1
        while(j>=0 and Array[j]>v):
            Array[j+1]=Array[j]
            j-=1
        Array[j+1]=v
        print(*A)

n=int(input())
A=[int(i) for i in input().split()]
print(*A)
insertion_sort(A,n)


