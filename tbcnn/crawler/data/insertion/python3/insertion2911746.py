def print_list(array, N):
    for i, e in enumerate(array):
        if i == N - 1:
            print(e)
        else:
            print(e, end=" ")

N = int(input())
a = [int(e) for e in input().split()]
print_list(a, N)
for i in range(1, N):
    v = a[i]
    j = i - 1
    while j >= 0 and a[j] > v:
        a[j+1] = a[j]
        j -= 1
    a[j+1] = v
    print_list(a, N)

