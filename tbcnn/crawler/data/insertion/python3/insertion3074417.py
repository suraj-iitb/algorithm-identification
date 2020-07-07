N = int(input())
S = list(map(int, input().split()))

j = 0
for i in range(N):
    key = S[i]
    j = i - 1
    while j>=0 and S[j] > key:
        S[j+1] = S[j]
        j-=1
    S[j+1] = key
    
    res = ""
    for i in range(N):
        res += str(S[i])
        if i < N-1:
            res += " "
    
    print(res)
