def bubble_sort():
    N = int(input())
    A = [int(_) for _ in input().split()]

    flag = True
    ans = 0
    i = 0

    while flag:
        flag = False
        for j in range(N-1, i, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                ans += 1
                flag = True
        i += 1
    #N-1からiの範囲で全てif文が満たされない時(並べ替えが完了した時)，flag=Falseとなり処理が終了する

    print(' '.join(map(str, A)))
    print(ans)

bubble_sort()
