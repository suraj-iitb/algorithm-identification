N = int(input())
As = list(map(int, input().split()))
cnt = 0
for i in range(N):
    minj = i
    for j in range(i,N):
        if As[j] < As[minj]:
            minj = j
    if minj != i:
        tmp = As[i]
        As[i] = As[minj]
        As[minj] = tmp
        cnt += 1
    
print(" ".join([str(a) for a in As]))
print(cnt)
