def selection_rort(a, n):
    count = 0
    for i in range(n):
        
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        a[minj], a[i] = a[i], a[minj]
        if minj != i:
          count += 1
        
    return a, count

n = int(input())
a = list(map(int, input().split()))

a, count = selection_rort(a, n)
print(" ".join(map(str,a)))
print(count)
