def counting_sort(array, maxval):
    m = maxval+100
    count = [0] * (m)
    for a in array:
        count[a] += 1
    i = 0
    for a in range(m):
        for c in range(count[a]):
            array[i] = a
            i += 1
    return array


N = int(input())
l = list(map(int, input().split()))
a = 0
li = counting_sort(l, N)
for a in range(N-1):
    print(li[a], end=" ")
print(li[N-1])

