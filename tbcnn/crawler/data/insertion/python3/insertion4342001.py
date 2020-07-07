N = int(input())
As = [int(x) for x in input().split()]

print(" ".join(map(str,As)))
for i in range(1,N):
    v = As[i]
    j = i - 1
    while j >= 0 and As[j] > v:
        As[j+1] = As[j]
        j -= 1
    As[j+1] = v
    print(" ".join(map(str,As)))
