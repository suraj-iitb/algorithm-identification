def selection(a, n):
    cnt = 0
    for i in range(n):
        flag = 0
        minj = i
        for j in range(i+1,n):
            if a[j] < a[minj]:
                minj = j
                flag = 1
        if flag == 1:
            temp = a[minj]
            a[minj] = a[i]
            a[i] = temp
            cnt += 1
    return cnt

n = int(input())
a = list(map(int, input().split()))

cnt = selection(a, n)   
ans = str(a[0])
for i in range(1,n):
    ans += ' '+str(a[i])           
print(ans)
print(cnt)
