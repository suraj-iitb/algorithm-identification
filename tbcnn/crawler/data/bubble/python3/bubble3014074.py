n = int(input())
s = [int(x) for x in input().split()]

cnt = 0
for i in range(n) :
    for j in range(n - 1, i, -1) :
        if s[j - 1] > s[j] :
            s[j - 1], s[j] = s[j], s[j - 1]
            cnt += 1     
print(" ".join(map(str, s)))
print(cnt)

