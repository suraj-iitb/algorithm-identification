x = int(input())
li = list(map(int, input().split()))

for i in range(x):
    v = li[i]
    j = i - 1
    while j >= 0 and li[j] > v:
        li[j+1] = li[j]
        j -= 1
    li[j+1] = v
    for j in range(x):
        if j != x-1:
            print(li[j], end=" ")
        elif j == x-1:
            print(li[j], end="\n")
