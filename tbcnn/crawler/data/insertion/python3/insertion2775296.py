n = int(input())
l = list(map(int,input().split()))

"""
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
"""
mm = ''
for i in range(n):
    mm = mm + ' ' + str(l[i])
print(mm.strip())

for i in range(1,n):
    m = ''
    v = l[i]
    j = i-1
    while j >= 0 and l[j]> v:
        l[j + 1] = l[j]
        j = j -1
    l[j+1] = v
    for i in range(n):
        m = m + ' ' + str(l[i])
    print(m.strip())

    
