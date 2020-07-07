def bubble_sort(array):
    flag = True
    while flag:
        flag = False
        for i in range(N-1, 0, -1):
            if array[i] < array[i-1]:
                array[i], array[i-1] = array[i-1], array[i]
                flag = True

def merge_count(array):
    if len(array) <= 1:
        return array, 0
    mid = len(array) // 2
    left, cl = merge_count(array[:mid])
    right, cr = merge_count(array[mid:])
    count = cl + cr
    left = list(reversed(left))
    right = list(reversed(right))
    for i in range(len(array)):
        if not left:
            array[i] = right.pop()
        elif not right:
            array[i] = left.pop()
        elif left[-1] <= right[-1]:
            array[i] = left.pop()
        else:
            array[i] = right.pop()
            count += len(left)
    return array, count

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    a, b = merge_count(A)
    print(*a)
    print(b)
