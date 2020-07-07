N = int(input())
A = []
Cnt = 0

for i in range(N):
    A.append(int(input()))


def InsertSort(g):
    global A, N, Cnt
    for i in range(g, N):
        j = i - g
        v = A[i]
        while j >= 0 and A[j] > v:
            Cnt += 1
            A[j + g] = A[j]
            j -= g
        A[j + g] = v


G = []
l = 0
while l <= N:
    G.append(l)
    l = 3 * l + 1
G.reverse()
s = ''
for g in G:
    s += str(g) + ' '
    InsertSort(g)
print(len(G))
print(s.rstrip())
print(Cnt)
for a in A:
    print(a)





