n = int(input())
s = [int(x) for x in input().split()]

cnt = 0
for i in range(len(s)):
    mini = i
    for j in range(i,len(s)):
        if(s[j] < s[mini]):
            mini = j
    
    if(i != mini):

        v = s[i]
        s[i] = s[mini]
        s[mini] = v
        cnt += 1


    
print(" ".join(map(str,s)))
print(cnt)
