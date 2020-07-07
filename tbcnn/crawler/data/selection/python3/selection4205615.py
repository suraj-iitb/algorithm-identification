N = int(input())
data = list(map(int, input().split()))
count = 0

for i in range(N):
    min = i
    for j in range(i, N):
        if data[j] < data[min]:
            min = j
    if min != i:
        data[i], data[min] = data[min], data[i]
        count += 1
            
print("%d" %data[0], end="")
for i in range(1, N):
    print(" %d" %data[i], end="")
print()
print(count)
