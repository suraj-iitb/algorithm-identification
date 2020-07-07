import copy


def partition(A, p, r):
    x = A[r]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x[1]:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i + 1


def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q-1)
        quicksort(A, q+1, r)


n = int(input())
data = []
for _ in range(n):
    mark, num = map(str, input().split())
    data.append([mark, int(num)])
data1 = copy.deepcopy(data)

quicksort(data, 0, n-1)

for i in range(n-1):
    if data[i][1] == data[i+1][1]:
        if data1.index(data[i]) > data1.index(data[i+1]):
            print("Not stable")
            break
else:
    print("Stable")

for d in data:
    print(' '.join(str(dd) for dd in d))
