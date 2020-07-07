n = int(input())
s = input()
s = s.split(" ")
count = 0
for i in range(n):
    s[i] = int(s[i])
for i in range(n):
    minj = i
    for j in range(i+1,n):
        if s[j] < s[minj]:
            minj = j
    if i!= minj:
        v = s[i]
        s[i] = s[minj]
        s[minj] = v
        count += 1
for i in range(n-1):
    print(s[i],end = " ")
print(s[n-1])
print(count)
