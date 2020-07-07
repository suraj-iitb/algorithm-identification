def read_n_lows_input(n):
    Alist=[int(input()) for i in range(n)]
    return Alist

def print_list(A):
    print(*A, sep=" ")

def print_list_multi_low(A):
    for i in A:
        print(i)
    
def insertion_sort(A, n, g, cnt):
    for i in range(g-1, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v
    return A, cnt

def shell_sort(A, n):
    cnt = 0
    G0 = [797161, 265720, 88573, 29524, 9841, 3280, 1093, 364, 121, 40, 13, 4, 1]
    G = [i for i in G0 if i <= n]
    m = len(G)
    print(m)
    print_list(G)
    for i in range(m):
        A, cnt = insertion_sort(A, n, G[i], cnt)
    print(cnt)
    print_list_multi_low(A)

n=int(input())
A = read_n_lows_input(n)

shell_sort(A, n)

