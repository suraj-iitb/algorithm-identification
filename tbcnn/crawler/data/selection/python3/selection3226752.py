n = int(input())

blist = list(map(int, input().split()))

cnt = 0

for i in range(n):
    minj = i
    for j in range(i, n):
        if blist[j] < blist[minj]:
            minj = j
    if i != minj:
        cnt += 1
        blist[i], blist[minj] = blist[minj], blist[i]

for i in range(n):
    if i == n-1:
        print(blist[i])
    else:
        print(str(blist[i]) + " ", end="")

print(cnt)

