N, *A = map(int, open(0).read().split())
cnt = 0


def insertion(A, N, g):
    global cnt
    for i in range(g, N):
        v = A[i]
        j = i-g
        while j >= 0 and A[j] > v:
            A[j], A[j+g] = A[j+g], A[j]
            cnt += 1
            j -= g


m = 1
G = [1]
while 3*G[-1]+1 < N:
    m += 1
    G.append(3*G[-1]+1)
G = G[::-1]

for g in G:
    insertion(A, N, g)

print(m)
print(*G)
print(cnt)
[print(a) for a in A]

