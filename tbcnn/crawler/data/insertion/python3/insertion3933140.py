n = int(input())
ls = list(map(str, input().split()))

for i in range(n):
    v = ls[i]
    j = i - 1
    while j >= 0 and int(ls[j]) > int(v):
        ls[j+1] = ls[j]
        j -= 1
    ls[j+1] = v
    print(' '.join(ls))
