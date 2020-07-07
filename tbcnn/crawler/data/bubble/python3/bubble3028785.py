def print_list(A):
    print(*A, sep=" ")

def swap(a, b):
    return b, a

def bubble_sort(A, n):
    flg = 1 #逆の隣接要素が存在する
    i = 0
    replace_num = 0
    while flg:
        flg = 0
        for j in range(n-1, i, -1):
            if A[j-1] > A[j]:
                A[j-1], A[j] = swap(A[j-1], A[j])
                flg = 1
                replace_num += 1 #交換回数
        i += 1
    print_list(A)
    print(replace_num)

n = int(input())
A = list(map(int,input().split()))

bubble_sort(A, n)
