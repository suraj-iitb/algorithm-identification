n = int(input())
a = list(map(int, input().split()))
count = 0

for i in range(0, n):
    minj = i
    for j in range(i, n):
        if a[j] < a[minj]:
            minj = j
    if i != minj:
        a[i], a[minj] = a[minj], a[i]
        count += 1
    
print(" ".join([str(num) for num in a]))
print(count)

