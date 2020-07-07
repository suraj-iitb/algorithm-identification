n = int(input())
nlist = list(map(int, input().split()))

ans = nlist.copy

for i in range(n):
    v = nlist[i]
    j = i - 1
    while j >= 0 and nlist[j] > v:
        nlist[j+1] = nlist[j]
        j -= 1
    nlist[j+1] = v

    for j in range(n):
        if j == n-1:
            print(nlist[j])
        else:
            print(str(nlist[j]) + " ", end="")

