n=int(input())
a=list(map(int,input().split()))
flag = 1
k = 0
swap_count = 0
while flag == 1:
    flag = 0
    for i in range(n-1,k,-1):
        if a[i-1] > a[i]:
            a[i],a[i-1] = a[i-1],a[i]
            flag = 1
            swap_count += 1
    k += 1
print(" ".join(map(str,a)))
print(swap_count)
