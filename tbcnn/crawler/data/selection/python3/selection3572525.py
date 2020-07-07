def lP(l: list) -> None:
    for i in range(len(l)-1):
        print(l[i], end = ' ')
    print(l[len(l)-1])

N = int(input())
l = list(map(int, input().split()))
sum = 0

for i in range(N):
    minI = i
    for j in range(i+1, N):
        if l[minI] > l[j]:
            minI = j
    if i != minI:
        l[i], l[minI] = l[minI], l[i]
        sum += 1
lP(l)
print(sum)
