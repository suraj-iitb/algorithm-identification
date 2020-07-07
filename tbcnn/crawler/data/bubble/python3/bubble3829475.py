n = int(input())
li = list(map(int, input().split()))
flag = 0
for i in reversed(range(n)):
    for j in range(i):
        if li[j] > li[j+1]:
            li[j], li[j+1] = li[j+1], li[j]
            flag += 1

print(*li)
print(flag)

