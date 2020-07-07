n = int(input())
a = list(map(int,input().split()))
for i in range(len(a)):
    v = a[i]
    j = i-1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
    for k in range(n):
        if k != n-1:
            print(a[k], end=' ')
        else:
           print(a[k], end='') 
    print()
