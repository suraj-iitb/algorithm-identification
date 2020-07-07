#bubble_sort
n = int(input())
a = list(map(int, input().split()))
cnt = 0
frag = 1
while frag:
    frag = 0
    for i in reversed(range(1, n)):
        if a[i-1] > a[i]:
            a[i-1],a[i] = a[i], a[i-1]
            cnt += 1
            frag = 1
print(*a)
print(cnt)
