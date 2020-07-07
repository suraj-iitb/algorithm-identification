n = int(input())

a = list(map(int,input().split()))

flag = 1
i = 0
count = 0

while flag:
    flag = 0
    for j in range(n-1,i,-1):
        if a[j] < a[j-1]:
            a[j],a[j-1] = a[j-1],a[j]
            count += 1
        flag = 1
        
    i += 1

for w in range(n):
    if w != n-1:
        print(a[w],end=" ")
    else:
        print(a[w])
print(count)
