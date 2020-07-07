def bubble_sort(a):
    cnt = 0
    size = len(a)
    for i in range(size):
        for j in range(size-1, i, -1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                cnt += 1

    return (a,cnt)

_ = input()
l = [ int(s) for s in input().split() ]
(nl,swap) =  bubble_sort(l)

print(*nl)
print(swap)
