def print_array(a):
    s = str(a[0])
    for i in range(1,n):
        s += ' '+str(a[i])
    print(s)
    return 0
n = int(input())
a = list(map(int, input().split()))

print_array(a)

for i in range(1,n):
    v = a[i]
    j = i -1
    while(j>=0 and a[j]>v):
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
    print_array(a)
