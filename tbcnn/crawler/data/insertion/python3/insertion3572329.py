def lP(l: list) -> None:
    for i in range(len(l)-1):
        print(l[i], end = ' ')
    print(l[len(l)-1])

N = int(input())
l = list(map(int, input().split()))
for i in range(1, N):
    lP(l)
    v = l[i]
    for j in range(i-1, -1, -1):
        if v >= l[j]:
            break
        l[j+1] = l[j]
        l[j] = v
lP(l)
