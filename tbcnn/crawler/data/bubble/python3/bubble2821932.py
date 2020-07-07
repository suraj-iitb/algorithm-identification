n = int(input())
a = list(map(int,input().split()))
cnt = 0
flag = True
while(flag):
    flag = False
    for j in list(range(1,n))[::-1]:
        if a[j] < a[j-1]:
            temp = a[j]
            a[j] = a[j-1]
            a[j-1] = temp
            flag = True
            cnt += 1
ans = str(a[0])
for i in a[1:]:
    ans += ' '+ str(i)
print(ans)
print(cnt)
