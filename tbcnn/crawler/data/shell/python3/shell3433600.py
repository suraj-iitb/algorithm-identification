def insertion_sort(A, increment):
    global N
    global swap
    for i in range(increment, N):
        key = A[i]
        j = i - increment
        while A[j] > key and j >= 0:
            A[j + increment] = A[j]
            j -= increment
            swap += 1
        A[j+increment] = key
    
def shell_sort(A, G): 
    for g in G:
        insertion_sort(A,g)
    return swap
        

N = int(input())
swap = 0 
A = [None for _ in range(N)]
for j in range(N):
    A[j] = int(input())
G = []
start = 1
while start <= N:
    G.append(start)
    start = 3 * start + 1
G = G[::-1]
print(len(G))
print(' '.join(list(map(str, G))))
swap = shell_sort(A, G)
print(swap)
for _ in A:
    print(_)
