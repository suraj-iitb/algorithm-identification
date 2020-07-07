N = int(input())
A = list(map(int, input().split()))

flg = True
ans = 0

while flg:
    flg = False
    for i in range(N-1):
        if A[i] > A[i+1]:
            A[i], A[i+1] = A[i+1], A[i]
            flg = True
            ans += 1
    
print(' '.join(list(map(str, A))))
print(ans)
