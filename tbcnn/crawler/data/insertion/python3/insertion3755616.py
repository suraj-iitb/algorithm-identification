n = int(input())
alist = list(map(int, input().split()))

print(" ".join([str(i) for i in alist]))

def insertion_sort(alist, n):
    for i in range(1, n):
        current = alist[i]
        j = i - 1
        while j >= 0 and alist[j] > current:
            alist[j], alist[j+1] = alist[j+1], alist[j]
            j -= 1
        print(" ".join([str(i) for i in alist]))

insertion_sort(alist, n)
