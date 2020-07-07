a = int(input())
n = list(map(int, input().split()))

print(*n)

for i in range(1, a):
    v = n[i]
    j = i - 1
    while j >= 0 and n[j] > v:
        n[j+1] = n[j]
        j -= 1
        n[j+1] = v
    print(*n)
