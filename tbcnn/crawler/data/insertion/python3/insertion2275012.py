def isort(seq, n):
    for i in range(1, n):
        x = seq[i]
        j = i - 1
        while j >= 0 and seq[j] > x:
            seq[j + 1] = seq[j]
            j -= 1
        seq[j + 1] = x
        print(*seq)


n = int(input())

x = list(map(int, input().split()))
print(*x)
isort(x, n)
