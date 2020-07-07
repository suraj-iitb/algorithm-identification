N = int(input())
IN = list(map(int,input().split()))
print(*IN)
for i in range(1,N):
    v = IN[i]
    j = i - 1
    while j >= 0 and IN[j] > v:
        IN[j+1] = IN[j]
        j -= 1
    IN[j+1] = v
    print(*IN)
