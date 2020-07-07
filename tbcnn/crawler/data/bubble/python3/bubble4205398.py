N = int(input())
data = list(map(int, input().split()))
count = 0

for i in range(1, N):
    for j in range(N-i):
        if data[N-1-j] < data[N-1-j-1]:
            data[N-1-j], data[N-1-j-1] = data[N-1-j-1], data[N-1-j]
            count += 1
            
print("%d" %data[0], end="")
for i in range(1, N):
    print(" %d" %data[i], end="")
print()
print(count)
