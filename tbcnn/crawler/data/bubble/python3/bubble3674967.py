N = int(input())
As = list(map(int, input().split()))

cnt = 0
flg = True
while flg:
    flg = False
    for i in range(N-1,0,-1):
        if As[i-1] > As[i]:
            tmp = As[i]
            As[i] = As[i-1]
            As[i-1] = tmp        
            flg = True
            cnt += 1
print(" ".join([str(a) for a in As]))
print(cnt)
