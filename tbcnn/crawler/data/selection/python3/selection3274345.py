def selectionSort(A, N):
    cnt = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        cnt = cnt + int(i != minj)
        A[i], A[minj] = A[minj], A[i]
    return cnt

N = int(input())
A = [int(i) for i in input().split()]
cnt = selectionSort(A, N)

for i in range(N):
    if i != 0:
        print(" ", end = "")
    print(A[i], end = "")
    

print()
print(cnt)

