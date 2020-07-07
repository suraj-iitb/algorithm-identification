n = int(input())

A = list(map(int, input().split()))

def swap(a, b):
    t = a
    a = b
    b = t
    return [a, b]

def bubble_sort(l):
    count = 0
    for i in range(0, len(l)):
        for j in reversed(range(i+1, len(l))):
            if l[j] < l[j-1]:
                count += 1
                l[j], l[j-1] = swap(l[j], l[j-1])
    return l, count

l, count = bubble_sort(A)
print(' '.join(str(x) for x in l))
print(count)
