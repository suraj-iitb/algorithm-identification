def insertionSort(a: list, n: int):
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        a_str = map(str, a)
        print(" ".join(a_str))

n = int(input())
a = list(map(int, input().split()))
a_str = map(str, a)
print(" ".join(a_str))
insertionSort(a, n)


