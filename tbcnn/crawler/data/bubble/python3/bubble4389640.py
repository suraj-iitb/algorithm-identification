N=int(input())
S=list(map(int,input().split()))

counter=0
for E in range(0,N):
    for i in range(N-1,E,-1):
        if S[i]<S[i-1]:
            this_value=S[i]
            S[i]=S[i-1]
            S[i-1]=this_value
            counter+=1
        else:pass

print(*S)
print(counter)
