def SelectionSort(N, A):
    count = 0
    if N == 1:
        print(str(A[0]) + "\n" + str(0))
    else:
        for i in range(N - 1):
            A_r = A[i:] #確定してないAの右側の領域
            mini = min(A_r)
            mini_index = i + A_r.index(mini) #+iの補正が必要
            if A[i] > mini:
                count += 1
                A[i], A[mini_index] = A[mini_index], A[i] 

        str_A = map(str, A)
        print(" ".join(str_A) + "\n" + str(count))


n = int(input())
a = list(map(int, input().split()))
SelectionSort(n, a)

