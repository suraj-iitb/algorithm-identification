n = int(input())
a = [int(i) for i in input().split()]

num = 0

is_swapped = True
while is_swapped:
    is_swapped = False
    for i in range(n-1, 0, -1):
        if a[i] < a[i-1]:
            tmp = a[i]
            a[i] = a[i-1]
            a[i-1] = tmp
            is_swapped = True
            num += 1

print(' '.join([str(i) for i in a]))
print(num)
