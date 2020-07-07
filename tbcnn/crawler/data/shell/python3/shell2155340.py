
def InsertionSort(A, n, g):
    cnt = 0

    for i in range(g, n):
        v = A[i]
        j = i - g

        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            cnt += 1

        A[j + g] = v

    return cnt

def ShellSort(A, n):
    tot_cnt = 0
    G = [1]
    span = 4

    while span < n:
        G.append(span)
        span = span * 3 + 1

    G.reverse()
    m = len(G)

    for g in G:
        tot_cnt += InsertionSort(A, n, g)

    return m, G, tot_cnt


n = int(input())
A = []

for i in range(n):
    A.append(int(input()))

m, G, tot_cnt = ShellSort(A, n)

print(m)
print(*G)
print(tot_cnt)
print(*A, sep = "\n")
