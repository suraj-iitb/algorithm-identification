n = int(input())
s = list(map(int, input().split()))

for i in range(n):
    v = s[i]
    j = i - 1
    while j >= 0 and s[j] > v:
        s[j+1] = s[j]
        j -= 1
    s[j+1] = v

    print(*s)
