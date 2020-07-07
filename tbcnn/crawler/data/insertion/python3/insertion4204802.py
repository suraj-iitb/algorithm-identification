N = int(input())
data = list(map(int, input().split()))
    
for i in range(N):
    tmp = data[i]
    j = i - 1
    while j >= 0 and data[j] > tmp:
        data[j+1] = data[j]
        j -= 1
    data[j+1] = tmp
    
    for j in range(N):
        print("%d" %(data[j]), end="")
        if j != N-1:
            print(" ", end="")
    print()

