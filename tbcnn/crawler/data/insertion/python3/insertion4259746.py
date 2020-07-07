n = int(input())
a = list(map(int,input().split()))
for i in range(n):
    j = i-1
    key = a[i]
    #print(key)
    while 0 <= j and key < a[j]:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = key
    print(" ".join(map(str,a)))
