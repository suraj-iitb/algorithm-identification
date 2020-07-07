n = int(input())
arr = list(map(int, input().split()))

reversals = 0
need_to_sort = True
while need_to_sort:
    need_to_sort = False
    for index in range(len(arr) -1, 0, -1):
        if arr[index] < arr[index-1]:
            arr[index], arr[index-1] = arr[index-1], arr[index]
            need_to_sort = True
            reversals += 1
print(" ".join(map(str, arr)), reversals, sep="\n")
