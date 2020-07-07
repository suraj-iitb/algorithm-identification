x = int(input())
*li, = list(map(int, input().split()))

ans = 0

for i in range(x):
    for j in range(x-1):
        if li[j] > li[j+1]:
            li[j], li[j+1] = li[j+1], li[j]
            ans += 1

print(*li)
print(ans)
