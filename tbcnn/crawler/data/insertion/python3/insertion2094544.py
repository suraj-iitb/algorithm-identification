n = int(input())
line = list(map(int,input().split()))
print(*line)
for i in range(1,n):
    v = line[i]
    j = i-1
    while j>=0 and line[j]>v:
        line[j+1] = line[j]
        j -= 1
    line[j+1] = v
    print(*line)
