def insertionSort(a, n):
    for i in range(n):
        if i != n-1:
            print(a[i], end=" ")
        else:
            print(a[i], end="")
    print("")
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        for i in range(n):
            if i != n-1:
                print(a[i], end=" ")
            else:
                print(a[i], end="")
        print("")

if __name__ == '__main__':
    n = int(input())
    a = []
    a = list(map(int, input().split()))
    insertionSort(a, n)

