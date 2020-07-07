n = int(input())
s = [int(x) for x in input().split()]

cnt = 0
for i in range(len(s)-1):
    for j in reversed(range(i+1,len(s))):
        if(s[j-1] > s[j]):
            v = s[j]
            s[j] = s[j-1]
            s[j-1] = v
            cnt += 1
            
print(" ".join(map(str,s)))
print(cnt)
