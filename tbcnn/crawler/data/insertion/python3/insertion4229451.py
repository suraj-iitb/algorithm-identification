N = int(input())
li = list(map(int, input().split()))

# N = 6
# li = [5, 2, 4, 6, 1, 3]

for i in range(1, N):
    print(*li)
    v = li[i]
    for j in reversed(range(0, i)):
        if li[j] > v:
            li[j + 1] = li[j]
            li[j] = v
        else:
            break

print(*li)

