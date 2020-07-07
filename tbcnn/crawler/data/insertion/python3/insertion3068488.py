input()
x = list(map(int, input().split()))

def insertion_sort(a):
    print(*a)
    for i in range(1, len(a)):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        print(*a)

insertion_sort(x)
