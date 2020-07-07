#coding:utf-8
#1_5_B
def merge(array, left, mid, right):
    global cnt
    L = array[left:mid]  + [sentinel]
    R = array[mid:right] + [sentinel]
    i = j = 0
    for k in range(left, right):
        if L[i] <= R[j]:
            array[k] = L[i]
            i += 1
        else:
            array[k] = R[j]
            j += 1
    cnt += right - left

def merge_sort(array, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(array, left, mid)
        merge_sort(array, mid, right)
        merge(array, left, mid, right)


n = int(input())
S = list(map(int, input().split()))
cnt = 0
sentinel = 10 ** 9 + 1
merge_sort(S, 0, len(S))
print(*S)
print(cnt)
