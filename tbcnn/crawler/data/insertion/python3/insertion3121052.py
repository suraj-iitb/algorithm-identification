#! python3
# insertion.py - 標準入出力を行う

N = int(input())
l = input().split(' ')
A = [int(i) for i in l]
# print(A)

def insertion(A, N): # N個の要素を含む0-オリジンの配列A
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = v
        map_list = map(str, A)
        a = ' '.join(map_list)
        print(a)

insertion(A, N)
