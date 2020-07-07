n = int(input())
a = list(map(int,input().split()))

for i in range(0,n):
    v = a[i]
    j = i - 1
    while 0 <= j and v < a[j]:
        a[j+1] = a[j]
        j = j - 1
    
    a[j+1] = v

    print(*a)
