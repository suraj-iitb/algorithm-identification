from sys import stdin

n = int(stdin.readline().rstrip())
A = [int(stdin.readline().rstrip()) for _ in range(n)]
count = 0

def sortInsert(A, n, g):
    global count
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j-g
            count += 1

        A[j+g] = v

def sortShell(A, n):
    m = [1]
    while n > 3*m[-1]+1:
        m = m + [3*m[-1]+1]
    
    m = m[::-1]
    print(len(m))
    print(*m)
    for i in range(len(m)):
        sortInsert(A, n, m[i])

sortShell(A, n)
print(count)
print(*A, sep="\n")
