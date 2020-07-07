N = int(input())
num_list = [int(item) for item in input().split()]

def bubbleSort(A, N):
    is_flag = 1
    cnt = 0

    while is_flag:
        is_flag = 0
        for i in range(N-1):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                is_flag = 1
                cnt += 1
    print(*A)
    print(cnt)

bubbleSort(num_list, N)
