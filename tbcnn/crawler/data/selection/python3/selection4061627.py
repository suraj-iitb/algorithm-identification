def SelectionSort(A, N):
    cnt=0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[minj] > A[j]:
                minj = j
        if minj != i:
            cnt +=1
        A[i], A[minj] = A[minj], A[i]       
    return A, cnt

N = int(input())
A = list(map(int, input().split()))

ans, cnt = SelectionSort(A, N)

print(*A)
print(cnt)
