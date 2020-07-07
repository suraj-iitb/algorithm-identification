N=int(input())
S=list(map(str,input().split()))

print(" ".join(S).rstrip())

for i in range(1,len(S)):
    
    for j in range(i):
        if int(S[j])>=int(S[i]):
            S.insert(j,S[i])
            del S[i+1]
    
        else:
            
            pass
    print(" ".join(S).rstrip())
