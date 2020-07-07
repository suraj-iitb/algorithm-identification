cnt = 0
n = int(input())
lst = list(map(int, input().split()))
for i in range(n):
    m = i
    for j in range(i, n):
        if lst[j] < lst[m]:
            m = j
    if m != i:
        lst[i], lst[m] = lst[m], lst[i]
        cnt += 1
print(*lst)
print(cnt)
