N = int(input())
I = list(map(int, input().split()))

cnt = 0
for i in range(1, N):
    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if I[j] < I[j-1]:
                tmp = I[j]
                I[j] = I[j-1]
                I[j-1] = tmp
                flag = True
                cnt += 1
print(str(I).replace(',','').replace('[','').replace(']',''))
print(cnt)


