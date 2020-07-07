n = int(input())
s = input()
print(s)
s = s.split(" ")
for i in range(n):
    s[i] = int(s[i])
for i in range(1,n):
    v = s[i]
    j = i-1
    while j >= 0 and s[j] > v:
        s[j+1] = s[j]
        j -= 1
    s[j+1] = v
    for k in range(n-1):
        print(s[k],end = " ")
    print(s[n-1])
