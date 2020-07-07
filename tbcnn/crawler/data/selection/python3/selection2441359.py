def main():
    N = int(input())
    A = tuple(map(int, input().split()))

    a = list(A)
    ans, n = selectionSort(a, N)
    print(*ans, sep=' ')
    print(n)

def selectionSort(a, n):
    k = 0
    for i in range(n - 1):
        minj = i
        for j in range(i + 1, n):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if a[i] != a[minj]:
            k += 1
    return a, k

main()
