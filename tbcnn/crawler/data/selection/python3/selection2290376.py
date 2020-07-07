#3.4

N = int(input())
a = list(map(int, input().split()))

swapCount = 0
for i in range(0, N):
    minIndex = i
    for j in range(i, N):
        if a[j] < a[minIndex]:
            minIndex = j
    
    if i != minIndex:
        tmp = a[i]
        a[i] = a[minIndex]
        a[minIndex] = tmp
        swapCount += 1

print(' '.join(map(str, a)))
print(swapCount)

        
