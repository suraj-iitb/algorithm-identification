import copy
def quicksort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quicksort(a, p, q-1)
        quicksort(a, q+1, r)

def partition(a, p, r):
    x = a[r][1]
    i = p - 1
    for j in range(p, r):
        if a[j][1] <= x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[r] = a[r], a[i + 1]
    return (i+1)

n = int(input())
a = [list(input().split()) for i in range(n)]

for i in range(n):
    a[i][1] = int(a[i][1])
b = copy.deepcopy(a)
quicksort(a, 0, n-1)


for i in range(n - 1):
    if a[i][1] == a[i + 1][1]:
        if b.index(a[i]) > b.index(a[i + 1]):
            print("Not stable")
            break
else:
    print("Stable")
    
for i in a:
    print(" ".join(map(str, i)))
