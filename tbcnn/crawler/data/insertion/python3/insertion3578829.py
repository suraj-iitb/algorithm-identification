def pr(sequence):
    string = ''
    for i in sequence[:-1]:
        string += str(i) + ' '
    string += str(sequence[-1])
    print(string)


n = int(input())
a = list(map(int, input().split()))

for i in range(1,n):
    pr(a)
    key = a[i]
    j = i -1
    while (j >=0) and (a[j] > key):
        a[j+1] = a[j]
        j = j-1
    a[j+1] = key
pr(a)


