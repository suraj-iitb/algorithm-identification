def merge_sort(left, right):
    if right-left > 1:
        mid = (left + right) // 2
        merge_sort(left, mid)
        merge_sort(mid, right)
        merge(left, mid, right)

def merge(left, mid, right):
    left_part = S[left:mid]
    right_part = S[mid:right]
    left_part.append(inf)
    right_part.append(inf)
    l, r = 0, 0
    for i in range(left, right):
        if left_part[l] < right_part[r]:
            S[i] = left_part[l]
            l += 1
        else:
            S[i] = right_part[r]
            r += 1
    num[0] += right-left

if __name__ == "__main__":
    num = [0]
    inf = float('inf')
    n = int(input())
    S = list(map(int, input().split()))
    merge_sort(0, n)
    print(' '.join(list(map(str, S))))
    print(num[0])
