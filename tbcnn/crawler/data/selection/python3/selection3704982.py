from sys import stdin
N = int(stdin.readline().rstrip())
nums = [int(_) for _ in stdin.readline().rstrip().split()]

def select_sort(a, n):
    count = 0
    for i in range(n):
        mini = i
        for j in range(i, n):
            if a[j] < a[mini]:
                mini = j
        if mini != i:
            count += 1
        a[i], a[mini] = a[mini], a[i]
    return a, count

ret, count = select_sort(nums, N)
print(*ret)
print(count)
