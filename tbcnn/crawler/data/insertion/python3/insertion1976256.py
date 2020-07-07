N = int(input())
l = list(map(int, input().split()))
for i in range(N):
    t = l[i]
    j = i-1
    while j >= 0 and l[j] > t:
        l[j+1], l[j] = l[j], l[j+1]
        j -= 1
    print(*l)
