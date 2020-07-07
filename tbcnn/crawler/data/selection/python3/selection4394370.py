N = int(input())
A = list(map(int,input().split()))

def selectionSort(A, N):
    cnt = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j

        temp = A[i]
        A[i] = A[minj]
        A[minj] = temp
        if i != minj:
            cnt += 1

    return(A, cnt)

out_A, cnt_sort = selectionSort(A,N)

out_A_str = list(map(str, out_A))
print(" ".join(out_A_str))
print(str(cnt_sort))
