#2_A
def bubble_sort(a,n):
    flag = 1
    count = 0
    while flag:
        flag = 0
        for i in range(n-1):
            j = n - 1 - i
            if a[j] < a[j-1]:
                v = a[j]
                a[j] = a[j-1]
                a[j-1] = v
                flag = 1
                count += 1
    return a, count

n = int(input())
a = list( map(int, input().split()) )

arr, count = bubble_sort(a, n)
res = str(arr[0])
for i in range(n-1):
    res += " " + str(arr[i+1])

print(res)
print(count)
