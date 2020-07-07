def selectionsort(a, n):
    count = 0
    for i in range(n):
        min = i
        for j in range(i, n):
            if a[min] > a[j]:
                min = j
        if i != min:
            count += 1
            a[i], a[min] = a[min], a[i]
    return count

N = int(input())
A = list(map(int, input().split()))

c = selectionsort(A, N)
print(*A)
print(c)
