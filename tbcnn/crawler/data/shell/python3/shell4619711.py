from sys import stdin, maxsize


def insertion_sort(A, n, g):
    cnt = 0
    for i in range(n):
        j = i
        tmp = A[j]
        while j - g >= 0 and A[j - g] > tmp:
            A[j] = A[j - g]
            j -= g
            cnt += 1
        A[j] = tmp
    return cnt


n = int(input())
A = [int(stdin.readline()) for i in range(n)]

G = [1]
for j in range(maxsize):
    k = 2**j + 1
    if k > n: break
    G += [k]

G.reverse()
m = len(G)

cnt = 0
for g in G:
    cnt += insertion_sort(A, n, g)

print(m)
print(*G)
print(cnt)
print("\n".join(map(str, A)))

