n = int(input())
a = [int(i) for i in input().split()]

cnt = 0

for i in range(n):
    m = i
    for j in range(i + 1, n):
        if a[j] < a[m]:
            m = j

    if not m == i:
        a[m], a[i] = a[i], a[m]
        cnt += 1


print(' '.join(map(str, a)))
print(cnt)


