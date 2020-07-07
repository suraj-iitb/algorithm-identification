n = int(input())
a = [int(i) for i in input().split()]

flag = 1
c = 0
while flag:
    flag = 0
    for i in range(1,n):
        j = n-i
        if a[j] < a[j-1]:
            a[j],a[j-1] = a[j-1],a[j]
            c += 1
            flag = 1

print(' '.join(map(str,a))) 
print(c)
