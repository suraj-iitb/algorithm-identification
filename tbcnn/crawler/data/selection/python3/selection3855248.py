n = int(input())
a = [int(x) for x in input().split()]
count = 0

for i in range(n):
    min_index = i
    
    for j in range(i+1, n):
        if a[j] < a[min_index]:
            min_index = j
            
    if i != min_index:
        a[i], a[min_index] = a[min_index], a[i]
        count += 1

print(' '.join([str(x) for x in a]))
print(count)
