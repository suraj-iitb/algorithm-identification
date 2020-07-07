n = int(input())
a = list(map(int,input().split()))

for i in range(n):
    v = a[i]
    j = i -1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
    
    for i in range(n-1):
        print(str(a[i]) + " ", end="")
    print(a[n-1])
