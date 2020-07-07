n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    temp = a[i]
    j = i - 1
    while j >= 0 and a[j] > temp:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = temp
    a_str = [str(s) for s in a]
    print(' '.join(a_str))
