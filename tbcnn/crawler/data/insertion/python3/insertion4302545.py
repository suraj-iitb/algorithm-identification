N = int(input())
a = [int(i) for i in input().split()]

for i in range(N):
    key = a[i]
    j = i-1
    while j>=0 and a[j] > key:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = key
    for k in range(N):
        arra = ' '.join([str(n) for n in a])

    print(arra)

