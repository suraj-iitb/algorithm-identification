N = int(input())
S = [int(input()) for i in range(N)]

count = 0
def insertionSort(S, N, g):
    global count
    for i in range(g, N):
        v = S[i]
        j = i - g
        while j >= 0 and S[j] > v:
            S[j+g] = S[j]
            j = j - g
            count += 1
        S[j+g] = v

def shellSort(S, N):
    h = 1
    G = []
    while h <= N:
        G.append(h)
        h = 3*h+1
    G.reverse()
    m = len(G)

    for i in G:
        insertionSort(S, N, i)

    print(m)
    print(' '.join([str(j) for j in G]))

shellSort(S, N)
print(count)
for i in S:
    print(i)
