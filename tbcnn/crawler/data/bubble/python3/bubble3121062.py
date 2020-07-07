#! python3
# insertion.py - 標準入出力を行う

N = int(input())
l = input().split(' ')
A = [int(i) for i in l]
# print(A)

def insertion(A, N): # N個の要素を含む0-オリジンの配列A
    flag = 1 # 逆の隣接要素が存在する
    i = 0 # 未ソート部分列の先頭インデックス
    counter = 0
    while flag == 1:
        flag = 0
        if i != N:
            for j in range(N-1, 0, -1):
                if A[j] < A[j-1]:
                    v = A[j]
                    A[j] = A[j-1]
                    A[j-1] = v
                    flag = 1
                    counter += 1
            i += 1
        map_list = map(str, A)
        a = ' '.join(map_list)
    print(a)
    print(counter)

insertion(A, N)
