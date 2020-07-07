N = int(input())
array = list(map(int,input().split()))
for dt in array:
    if dt==array[-1]:
        print(dt)
    else:print(dt,end=" ")
for n in range(1,N):
    for m in range(n-1,-1,-1):
        if array[m]>array[m+1]:
            tmp=array[m]
            array[m]=array[m+1]
            array[m+1]=tmp
    for dt in array:
        if dt==array[-1]:
            print(dt)
        else:print(dt,end=" ")
