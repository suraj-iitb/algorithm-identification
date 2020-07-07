n = int(input())
numL = [0 for i in range(n)]

x = input()
for i in range(n):
    numL[i] = int(x.split()[i])

ctr = 0
for i in range(n-1):
    min = i
    for j in range(i+1,n):
        if numL[j] < numL[min]:
            min = j
    if min == i:
        pass
    else:
        ctr += 1
        tmp = numL[i]
        numL[i] = numL[min]
        numL[min] = tmp

print(*numL)
print(ctr)
