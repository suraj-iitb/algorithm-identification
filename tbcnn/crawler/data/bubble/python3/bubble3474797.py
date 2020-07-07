c = 0
N = int(input())

num = list(map(int, input().split()))

for i in range(N - 1):
    for j in reversed(range(i + 1, N)):
        if num[j - 1] > num[j]:
            p = num[j]
            num[j] = num[j - 1]
            num[j - 1] = p
            c += 1

print(" ".join(map(str, num)))
print(c)

