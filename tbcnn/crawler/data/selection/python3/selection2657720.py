n = int(input())
a = list(map(int, input().split()))

def selectionSort(a, n):
    count = 0
    for i in range(n):
        mini = i
        for j in range(i, n):
            if a[j] < a[mini]:
                mini = j
        if i != mini:
            a[i],a[mini] = a[mini],a[i]
            count += 1
    print(*a)
    print(count)

selectionSort(a,n)
