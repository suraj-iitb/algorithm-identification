def bubbleSort(A,N):
    flag = 1
    swapCount = 0
    while flag == 1 :
        flag = 0
        for j in range(N-1,0,-1):
            #一度逆順の要素があればその存在を仮定する。
            if A[j] < A[j-1] :
                v = A[j]
                A[j] = A[j-1]
                A[j-1] = v
                swapCount += 1
                flag = 1
    str = ""
    for i in range(N):
        str += "{} ".format(A[i])
    print(str[:len(str)-1])
    print(swapCount)


if __name__ == '__main__':
    N = int(input())
    A = [int(_) for _ in input().split()]

    bubbleSort(A,N)

