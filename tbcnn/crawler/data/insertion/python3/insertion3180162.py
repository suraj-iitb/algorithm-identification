N = int(input())
lst = list(map(int, input().split()))
def printInt(L):
    print(" ".join(map(str, L)))
for i in range(N):
    j = 0
    while j < i:
        if lst[j] > lst[i]:
            break
        j += 1
    tmp = lst[i]
    for x in range(i, j, -1):
        lst[x] = lst[x - 1]
    lst[j] = tmp
    printInt(lst)
