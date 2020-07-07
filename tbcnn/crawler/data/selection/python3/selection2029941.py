n = int(input())
m = list(map(int, input().split()))

count = 0
for i in range(n-1):
    minj =i
    for j in range(i+1, n):
        if m[j] < m[minj]:
            minj = j
    if m[i] != m[minj]:
        m[i], m[minj] = m[minj], m[i]
        count += 1


print(" ".join(str(x) for x in m))
print(count)
