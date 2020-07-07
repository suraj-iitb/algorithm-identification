n = int(input())
m = list(map(int, input().split()))

count = 0
flag = 1
while flag:
    flag = 0
    for j in range(n-1, 0, -1):
        if m[j] < m[j-1]:
            m[j], m[j-1] = m[j-1], m[j]
            count += 1
            flag = 1

print(" ".join(str(x) for x in m))
print(count)
