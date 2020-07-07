import math
n = int(input())
num = list(map(int, input().split()))
cnt = 0
flag = 1
while flag == 1:
    flag = 0
    for i in range(n-1, 0, -1):
        if num[i] < num[i-1]:
            num[i], num[i-1] = num[i-1], num[i]
            cnt+=1
            flag = 1
print(" ".join(map(str,num)))
print(cnt)

