def main():
    N = int(input())
    A = tuple(map(int, input().split()))

    a = list(A)
    print(*a, sep=' ')
    insertionSort(a, N)

def insertionSort(a, n):
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        print(*a, sep=' ')

main()
