def insertionSort(A, n, g):
    cnt = 0
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt = cnt + 1
        A[j+g] = v
    return cnt

n = int(input())
a = []
g = []
for i in range(n):
    x = int(input())
    a.append(x)
count = 0
m = 1;
while m<= n:
    g.append(m)
    m = (m*3) + 1
l = len(g)
print(str(l))
l = l-1
while l>0:
    print(str(g[l]) + " ", end = '')
    count += insertionSort(a, n, g[l])
    l = l-1
print(str(g[l]))
count += insertionSort(a, n, g[l])
print(str(count))
for i in a:
    print(str(i))

