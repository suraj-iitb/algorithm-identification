N = int(input())
A = list(map(int, input().split()))


def bubble_sort(A, N):
    cnt = 0
    flag = True
    while(flag):
        flag = False
        for i in range(N-1, 0, -1):
            if(A[i-1] > A[i]):
                A[i-1], A[i] = A[i], A[i-1]
                cnt += 1
                flag = True

    print(" ".join(list(map(str, A))))
    print(cnt)

bubble_sort(A, N)
