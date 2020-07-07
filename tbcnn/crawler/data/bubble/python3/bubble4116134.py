"""
1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
2   flag = 1 // 逆の隣接要素が存在する
3   while flag
4     flag = 0
5     for j が N-1 から 1 まで
6       if A[j] < A[j-1]
7         A[j] と A[j-1] を交換
8         flag = 1
"""


def bubble_sort(lists, n):
    flag = 1
    x = 0
    while flag:
        flag = 0
        for j in range(n - 1, 0, -1):
            if lists[j] < lists[j - 1]:
                lists[j], lists[j - 1] = lists[j - 1], lists[j]
                x += 1
                flag = 1

    return lists, x


def main():
    N = int(input())
    lists = list(map(int, input().split(' ')))
    lists_answer, x = bubble_sort(lists, N)
    print(' '.join(map(str, lists_answer)))
    print(x)


if __name__ == '__main__':
    main()
