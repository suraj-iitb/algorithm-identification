n = int(input())
arr = list(map(int, input().split()))
change = 0

for i in range(n):
    minj = i
    for j in range(i, n):
        if arr[j] < arr[minj]:
            minj = j
    else:
        if i != minj:
            arr[i], arr[minj] = arr[minj], arr[i]
            change += 1

def print_space(li):
    for i in range(len(li)-1):
        print(li[i], end=' ')
    else:
        print(li[-1])

print_space(arr)
print(change)
