N = int(input())
A = list(map(int,input().split()))

def bubbleSort(A, N):
    cnt = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                temp = A[j]
                A[j] = A[j-1]
                A[j-1] = temp
                flag = 1
                cnt += 1
    return(A, cnt)

out_A, cnt_sort = bubbleSort(A,N)

out_A_str = list(map(str, out_A))
print(" ".join(out_A_str))
print(str(cnt_sort))

