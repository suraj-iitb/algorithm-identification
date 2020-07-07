import sys
count = 0

def insertionSort(A, n, g):
    global count
    for i in range(n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            count += 1
        A[j+g] = v
    return A

def shellSort(A, n):
    for i in range(m):
        insertionSort(A, n, G[i])
    return A

n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

G = [1]
m = 1
while True:
    x = 3 * G[m-1] + 1
    if x >= n: break
    G.append(x)
    m += 1
G = G[::-1]

shellSort(A, n)

print(m)
print(' '.join([str(i) for i in G]))
print(count)
for i in A:
    print(i)
