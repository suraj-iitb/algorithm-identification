N = int(input())
li = list(map(int, input().split()))

num_swap = 0
flag = 1

while flag:
    flag = 0
    for j in reversed(range(N - 1)):
        if li[j + 1] < li[j]:
            temp = li[j + 1]
            li[j + 1] = li[j]
            li[j] = temp
            flag = 1
            num_swap += 1

print(*li)
print(num_swap)

