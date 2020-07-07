def insertingSort(a, n):
    for i in range(1, n):
        v = a[i]
        j = i - 1
        while j >= 0 and v < a[j]:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v 
        print(' '.join(list(map(str, a))))        

n = int(input().strip())
a = list(map(int, input().strip().split()))
print(' '.join(list(map(str, a))))
insertingSort(a, n)
