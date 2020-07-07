N = int(input())
lst = [int(input()) for i  in range(N)]

def insertion_sort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while(j >= 0 and A[j] > v):
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v

def shell_sort(A, n, m, G):    
    for i in range(m):
        insertion_sort(A, n, G[i])

cnt = 0
G = [1]
for i in range(99):
    if N < 1 + 3*G[-1]:
        break
    G.append(1 + 3*G[-1])
m = len(G)
G.reverse()

shell_sort(lst, N, m, G)

print(m)
print(" ".join(list(map(str, G))))
print(cnt)
for i in lst:
    print(i)
