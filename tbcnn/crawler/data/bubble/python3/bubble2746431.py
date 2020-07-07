n = int(input())
s = input()
s = s.split(" ")
for i in range(n):
    s[i] = int(s[i])
flag = 1
count = 0
while flag:
    flag = 0
    for i in range(1,n):
        if s[i] < s[i-1]:
            v = s[i]
            s[i] = s[i-1]
            s[i-1] = v
            flag = 1
            count += 1
for i in range(n-1):
    print(s[i],end = " ")
print(s[n-1])
print(count)
