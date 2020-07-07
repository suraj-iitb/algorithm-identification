def bubbleSort(A, N): # N 個の要素を含む 0-オリジンの配列 A
    flag = 1 # 逆の隣接要素が存在する
    counter = 0
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                counter += 1
                buf = A[j]
                A[j] = A[j-1]
                A[j-1] = buf
                flag = 1
    return A, counter

if __name__ == '__main__':
    N = int(input())
    a = list(map(int, input().split()))
    a, num = bubbleSort(a, N)
    for i in range(len(a)):
        if i != len(a)-1:
            print(a[i], end=" ")
        else:
            print(a[i])
    print(num)

