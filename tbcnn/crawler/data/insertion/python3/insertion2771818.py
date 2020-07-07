c = int(input())
s = list(map(int, input().split()))

for x in range(1, len(s)):
    print(*s, sep=' ')
    stash = s[x]
    if stash < s[x-1]:
        y = x
        while True:
            s[y] = s[y-1]
            y -= 1
            if y == 0 or stash > s[y-1]:
                break
        s[y] = stash
print(*s, sep=' ')

