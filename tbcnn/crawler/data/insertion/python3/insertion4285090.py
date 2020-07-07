n = int(input())
a = [int(i) for i in input().split()]
print(" ".join(map(str,a)))
for i in range(1,n):
    v = a[i]
    j = i-1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
    print(" ".join(map(str,a)))
