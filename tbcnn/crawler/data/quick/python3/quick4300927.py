from collections import defaultdict

def partition(arr, p: int, r: int):
    x = int(arr[r][1])
    i = p - 1
    for j in range(p, r):
        if int(arr[j][1]) <= x:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[r] = arr[r], arr[i + 1]
    return i + 1

def quick_sort(arr, p: int, r: int):
    if p < r:
        q = partition(arr, p, r)
        quick_sort(arr, p, q - 1)
        quick_sort(arr, q + 1, r)

n = int(input())
arr = [input().split() for _ in range(n)]
stable_dict = defaultdict(list)
stable_list = []

for a in arr:
    stable_dict[int(a[1])].append(a[0])

stable_dict = sorted(stable_dict.items(), key = lambda x: x[0])

for key, values in stable_dict:
    for v in values:
        stable_list.append([v, str(key)])

quick_sort(arr, 0, n - 1)

is_stable = 'Stable'
for (a, s) in zip(arr, stable_list):
    if ''.join(a) != ''.join(s):
        is_stable = 'Not stable'
        break
print(is_stable)

for a in arr:
    print(*a)

