def bubble_sort(A, N):
    exchange_cnt = 0
    flg = True
   
    while flg:
        flg = False
        for i in range(1, N)[::-1]:
            if A[i - 1] > A[i]:
                A[i], A[i - 1] = A[i - 1], A[i]
                flg = True
                exchange_cnt += 1
    print(" ".join([str(a) for a in A]))
    print(exchange_cnt)

N = int(input().rstrip())
A = [int(num) for num in input().rstrip().split(" ")]
bubble_sort(A, N)
