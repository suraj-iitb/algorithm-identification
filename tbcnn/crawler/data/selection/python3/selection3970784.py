N = int(input())
A = list(map(int,input().split()))

cnt = 0
for i in range(len(A)):
    mini = i
    for j in range(i,len(A)):
        if A[j] < A[mini]:
            mini = j
    if i != mini:
        #一番小さい値が確定して，先頭にくる
        A[i],A[mini] = A[mini],A[i]
        cnt += 1
print(*A)
print(cnt)
