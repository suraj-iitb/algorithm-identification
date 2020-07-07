n = int(input())

A = list(map(int, input().split()))

count = 0
def swap(a, b):
    t = a
    a = b
    b = t
    return [a, b]

def selection_sort(l):
    global count
    for i in range(0, len(l)):
        mini = i
        for j in range(i, len(l)):
            if l[j] < l[mini]:
                mini = j
        if i != mini:
            count += 1
        l[i], l[mini] = swap(l[i], l[mini])
    return l

l = selection_sort(A)
print(' '.join(str(x) for x in l))
print(count)
