def insertionSort(A, g):
    cnt = 0

    for i in range(g, len(A)):
        v = A[i]
        j = i - g
        
        while j >= 0 and A[j] > v:
            A[j + g] = A[j]
            j -= g
            cnt += 1

        A[j + g] = v

    return cnt


def shellSort(A):
    cnt = 0

    m = 0
    G = []
    gap = len(A) // 2

    while gap > 0:

        G.append(gap)

        cnt += insertionSort(A, gap)

        m += 1
        gap //= 2

    if not G:
        m = 1
        G.append(1)

    return m, G, cnt



# INPUT
n = int(input())

A = [int(input()) for _ in range(n)]

# SORT
m, G, cnt = shellSort(A)

# OUTPUT
print(m)

print(*G)

print(cnt)

for i in range(n):
    print(A[i])




