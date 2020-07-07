def insertionSort(A, n, g):
        global count
        for i in range(g, n):
                v = A[i]
                j = i - g
                while j >= 0 and A[j] > v:
                        A[j + g] = A[j]
                        j = j - g
                        count += 1
                A[j + g] = v

def shellSort(A, n):
        global count
        count = 0
        G = [1]
        h = 4
        while h < n:
                G.append(h)
                h = 3 * h + 1
        G.reverse()
        m = len(G)
        strG = map(str, G)

        print(m)
        print(" ".join(strG))
        for i in range(m):
                insertionSort(A, n, G[i])

num = int(input())
array = []

for i in range(num):
        array.append(int(input()))

shellSort(array, len(array))
print(count)

for i in range(num):
        print(array[i])
