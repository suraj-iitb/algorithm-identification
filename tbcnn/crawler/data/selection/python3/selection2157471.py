def selection_sort(N, a):
    c = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            a[i], a[minj] = a[minj], a[i]
            c += 1
    return a, c

ans, cnt = selection_sort(int(input()), [int(s) for s in input().split()])
print(' '.join(str(s) for s in ans), cnt, sep='\n')
