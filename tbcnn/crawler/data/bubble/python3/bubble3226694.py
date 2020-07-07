n = int(input())

blist = list(map(int, input().split()))

cnt = 0

for i in range(n):
    for j in range(n-1, i, -1):
        if blist[j] < blist[j-1]:
            cnt += 1
            blist[j], blist[j-1] = blist[j-1], blist[j]

for i in range(n):
    if i == n-1:
        print(blist[i])
    else:
        print(str(blist[i]) + " ", end="")

print(cnt)

