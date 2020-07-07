#! python3
# selectSort.py - 選択ソートを行う 配列の端から、残りのすべての数の一番小さい数と交換していく

N = int(input())
l = input().split(' ')
A = [int(i) for i in l]
# print(A)

def selectSort(A, N):
    counter = 0
    for i in range(N-1):
        minij = i
        for j in range(i + 1, N):
            if A[minij] > A[j]:
                minij = j

        if A[i] > A[minij]:
            v = A[i]
            A[i] = A[minij]
            A[minij] = v
            counter += 1

    map_list = map(str, A)
    a = ' '.join(map_list)
    print(a)
    print(counter)

selectSort(A, N)
