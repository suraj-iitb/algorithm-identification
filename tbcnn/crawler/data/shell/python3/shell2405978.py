def InsertionSort(a, N, Gap):
    c = 0
    for i in range(Gap, N):
        v = a[i]
        j = i - Gap
        while j >= 0 and a[j] > v:
            a[j+Gap] = a[j]
            j -= Gap
            c += 1
        a[j+Gap] = v
    return a, c

def ShellSort(a, N):
    cnt = 0
    G = [1]
    for i in range(1, N):
        if (3*G[i-1]+1) <= N:
            G.append(3*G[i-1]+1)
        else:
            break
            
    for g in G[::-1]:
        a, c = InsertionSort(a, N, g)
        cnt += c
    return a, cnt, G


N = int(input())
A = []
cnt = 0

for _ in range(N):
    A.append(int(input()))


sorted_A, cnt, G = ShellSort(A, N)
print(len(G))
print(*G[::-1])
print(cnt)
print(*sorted_A, sep="\n")
