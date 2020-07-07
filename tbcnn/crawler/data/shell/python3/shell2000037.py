import sys
n = int(input())
A = list(map(int, sys.stdin))

cnt = 0
def insertion_sort(L, n, g):
    global cnt
    for i in range(g, n):
        v = L[i]
        j = i - g
        while 0 <= j and v < L[j]:
            L[j+g] = L[j]
            j -= g
            cnt += 1
        L[j+g] = v


def shell_sort(L, n):
    global G
    for i in G:
        insertion_sort(L, n, i)

G = [i for i in [262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1] if i <= n]
shell_sort(A, n)

print(len(G))
print(' '.join(str(x) for x in G))
print(cnt)
for i in A:
    print(i)
