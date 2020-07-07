n = int(input())
a = list(map(int, input().split()))

f = True
ans = 0

while f:
    f = False
    for i in range(1, len(a)):
        if a[i] < a[i - 1]:
            ans += 1
            a[i], a[i - 1] = a[i - 1], a[i]
            f = True

print(*a)
print(ans)
