n = int(input())
li = list(map(int, input().split()))

for i in range(n):
    v = li[i]
    j = i - 1
    while j >= 0 and li[j] > v:
        li[j+1] = li[j]
        j -= 1
    li[j+1] = v
    print(str(li).replace(',', '')[1:-1])
