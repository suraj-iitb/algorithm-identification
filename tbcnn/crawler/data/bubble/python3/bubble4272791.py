n = int(input())
numL = [0 for i in range(n)]

x = input()
for i in range(n):
    numL[i] = int(x.split()[i])

flag = 1
ctr = 0
while flag:
    flag -= 1
    for i in range(n-1,0,-1):
        if numL[i] < numL[i-1]:
            ctr += 1
            tmp = numL[i]
            numL[i] = numL[i-1]
            numL[i-1] = tmp
            flag = 1
print(*numL)
print(ctr)

