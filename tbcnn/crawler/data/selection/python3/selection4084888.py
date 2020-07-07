def selectionSort(a,n):
    r = 0
    for i in range(n):
        minj = i
        for j in range(i,n):
            if a[j] < a[minj]:
                minj = j
        a[i], a[minj] = a[minj], a[i]
        if a[i] != a[minj]:
            r += 1
    return r


n = int(input())
a = list(map(int,input().split()))

r = selectionSort(a,n)

print(*a)
print(r)
