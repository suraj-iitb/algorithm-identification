def selection_sort(a,n):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i,n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            a[i],a[minj] = a[minj],a[i]
            count += 1

    return (a,count)

n = int(input())
a = list(map(int, input().split()))
a,c = selection_sort(a,n)
print(' '.join(map(str, a)))
print(c)
