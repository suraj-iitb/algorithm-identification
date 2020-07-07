n = int(input())
a = list(map(int, input().split()))
flag = 1
count = 0
while flag:
    flag = 0
    for i in range(n-1,0,-1):
        if a[i]<a[i-1]:
            a[i],a[i-1] = a[i-1],a[i]
            flag = 1
            count+=1
print(*a)
print(count)

