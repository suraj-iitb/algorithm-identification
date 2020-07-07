n = int(input())
a = list(map(int, input().split()))

def bubble_sort(a, n):
    counter = 0
    for i in range(n-1, 0, -1):
        for j in range(i):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]
                counter += 1

    return a, counter

a, counter = bubble_sort(a, n)
print(" ".join(map(str, a)))
print(counter)
