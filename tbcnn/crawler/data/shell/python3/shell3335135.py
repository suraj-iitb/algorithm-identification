import math

n = int(input())  # リストAの要素数
A = [int(input()) for i in range(n)]

# G = [4, 2, 1]
G = []
cnt = 0

tmp = math.floor(n / 2)
G.append(tmp)
while tmp > 1:
    tmp = math.floor(tmp / 2)
    G.append(tmp)


def insertion_sort(A, n, g):
    """[summary]

    Args:
        A ([type]): ソート対象の配列
        n ([type]): Aの要素数
        g ([type]): シェルソートの間隔
    """
    global cnt
    for i in range(g, n):
        tmp = A[i]
        j = i - g
        while j >= 0 and A[j] > tmp:
            A[j + g] = A[j]
            j = j - g
            cnt += 1
        A[j + g] = tmp


def shell_sort(A, n):
    global cnt
    for g in G:
        insertion_sort(A, n, g)


shell_sort(A, n)
print(len(G))
print(' '.join(map(str, G)))
print(cnt)
for a in A:
    print(a)
