#2_B
def selection_sort(a,n):
    count = 0
    for i in range(n):
        minj = i
        m = n-1-i+1
        for j in range(m):
            k = i + j
            if a[k] < a[minj]:
                minj = k
        
        if minj!=i:
            minnum = a[minj]
            a[minj] = a[i]
            a[i] = minnum
            count += 1
    return a, count

n = int(input())
a = list( map(int, input().split()) )

arr, count = selection_sort(a, n)
res = str(arr[0])
for i in range(n-1):
    res += " " + str(arr[i+1])

print(res)
print(count)
