def bubble_sort(a, n):
    j = 0
    is_loop = True
    count = 0
    
    while is_loop:
        is_loop = False
        for i in range(n - 1, j, -1):
            if a[i] < a[i - 1]:
                a[i], a[i - 1] = a[i - 1], a[i]
                count += 1
                is_loop = True
        j += 1
        
    return count


N = int(input())
A = list(map(int, input().split()))

count = bubble_sort(A, N)

print(*A)
print(count)

