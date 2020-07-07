def selectionSort(A, N): # N個の要素を含む0-オリジンの配列A
    A = list(map(int, A.split(" ")))
    change_count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            #A[i] と A[minj] を交換
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            change_count+=1
    
    # 回答
    print(" ".join(map(str,A)))
    print(change_count)
    #return True

# 入力
N = int(input())  # 数列の長さを表す整数（N）
A = input("")   # N個の整数が空白区切り
selectionSort(A,N)

