def buble_sort(a,n):
    flag = True
    count = 0
    while flag:
        flag = False
        for j in range(n-1,0,-1):
            if a[j] < a[j-1]:
                a[j],a[j-1] = a[j-1],a[j]
                count += 1
                flag = True
    return (a,count)

n = int(input())
a = list(map(int, input().split()))
a,c = buble_sort(a,n)
print(' '.join(map(str, a)))
print(c)
