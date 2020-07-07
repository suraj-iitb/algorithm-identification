def selection(A,N):
    global cnt
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i],A[minj] = A[minj],A[i]
            cnt += 1
    return A

n = int(input())
a = [int(s) for s in input().split()]
cnt = 0
print(" ".join(map(str,selection(a,n))))
print(cnt)
