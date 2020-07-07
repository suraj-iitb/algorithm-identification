from sys import stdin
N = int(stdin.readline().rstrip())
nums = [int(_) for _ in stdin.readline().rstrip().split()]

def bubble_sort(a, n):
    count = 0
    flag = 1
    while flag:
        flag = 0
        for i in range(N-1, 0, -1):
            if a[i] < a[i-1]:
                a[i], a[i-1] = a[i-1], a[i]
                flag = 1
                count += 1
    return a, count

ret, count = bubble_sort(nums, N)
print(*ret)
print(count)
