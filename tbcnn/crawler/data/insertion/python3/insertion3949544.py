n = int(input())
list1 = list(map(int,input().split()))
for i in range(0,n):
    v = list1[i]
    for j in range(i,-1,-1):
        if list1[j] > v:
            tmp = list1[j]
            list1[j] = v
            list1[j+1] = tmp
            
    for m in range(n):
        if m == n-1:
            print(list1[m])
        else:
            print(list1[m],end=' ')

