def insertionSort(n,a):
    for i in range(1,n):
        x = a[i]
        j = i
        print(*a)
        while j>0 and x < a[j-1]:
            a[j] = a[j-1]
            j -= 1
            a[j] = x

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))

    insertionSort(n,a)
    print(*a)

