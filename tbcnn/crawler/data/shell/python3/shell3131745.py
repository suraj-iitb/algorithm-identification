import math
def insertionSort(A, N, h):
    global cnt
    for i in range(h, N):
        v = A[i]
        j = i - h
        while j >= 0 and A[j] > v:
            A[j + h] = A[j]
            j = j - h
            cnt += 1
        A[j + h] = v

N = int(input())
A = [int(input()) for _ in range(N)]
G = [int((3 ** i - 1) // 2) for i in range(1, int(math.log(2 * N + 1)) + 1) if int((3 ** i - 1) // 2) < N]
if G == []: G.append(1)
G.reverse()
cnt = 0
for h in G:
    insertionSort(A, N, h)
print(len(G))
print(*G)
print(cnt)
print(*A, sep = '\n')

