n = int(input())
s = list(map(int, input().strip().split(' ')))
e = int()
e = 0
flag = True
while flag:
        flag = False
        for i in range(n - 1, 0, -1):
            if s[i] < s[i - 1]:
                s[i - 1], s[i] = s[i], s[i - 1]
                e = e + 1
                flag = True

for i in range(0 , len(s)):
    if i != len(s) - 1:
        print(s[i], end=" ")
    else:
        print(s[i])

print(e)

