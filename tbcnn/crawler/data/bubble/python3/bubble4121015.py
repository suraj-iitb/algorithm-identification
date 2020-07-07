def bubble_sort(a, n):
    count = 0
    flag = 1
    
    while flag:
        flag = 0
        
        for j in range(n-1, 0, -1):
            if a[j] < a[j-1]:
                a[j-1], a[j] = a[j], a[j-1]
                flag = 1
                count += 1
                
    return a, count
            


n = int(input())
a = list(map(int, input().split()))

a, count = bubble_sort(a, n)

print(" ".join(map(str, a)))
print(count)
