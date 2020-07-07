c = int(input())
s = input().split()
count = 0
for j in range(c):
    for i in range(c-1,j,-1):
        if int(s[i]) < int(s[i-1]):
            s[i],s[i-1] = s[i-1],s[i]
            count += 1
print(" ".join(s))
print(count)
