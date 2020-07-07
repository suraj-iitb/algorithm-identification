n = int(input())
a_str = input()
print(a_str)
a = list(map(int, a_str.split()))

for i in range(0, n-1):
    v = a[i+1]
    j = i
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
        #print(i, a, v, j+1)
    a[j+1] = v
    print(' '.join(map(str, a)))

