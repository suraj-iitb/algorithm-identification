N = int(input())
li = list(map(int,input().split()))
print(*li)

for i in range(1,N):
    v = li[i]
    j = i - 1
    while j >= 0 and li[j] > v:
        li[j+1] = li[j]
        j -= 1
    li[j+1] = v
    print(*li)
