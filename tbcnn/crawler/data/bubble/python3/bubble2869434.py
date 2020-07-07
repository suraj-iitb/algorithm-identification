def bubbleSort(a,n):
    flag = 1
    c=0
    while(flag):
        flag = 0
        for i in reversed(range(1,len(a))):
            if(a[i] < a[i-1]):
                a[i],a[i-1] = a[i-1],a[i]
                c += 1
                flag = 1
    return [a,c]

n = int(input())
a = list(map(int,input().split(' ')))
sa , c = bubbleSort(a, n)
str = " ".join([str(i) for i in sa])
print("{}\n{}".format(str,c))
