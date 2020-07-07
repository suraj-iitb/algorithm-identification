
def selection_sort(a):
    size = len(a)
    cnt = 0
    for i in range(size):
        mini = i
        for j in range(i,size):
            if a[j] < a[mini]:
                mini = j
        if mini != i:
            a[i], a[mini] = a[mini], a[i]
            cnt += 1
    return (a, cnt)


_ = input()
l = [ int(s) for s in input().split() ]
(nl,swap) =  selection_sort(l)

print(*nl)
print(swap)
