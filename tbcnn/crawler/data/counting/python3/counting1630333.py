#coding:utf-8
#1_6_A
def counting_sort(array):
    cnt = [0 for i in range(max(array)+1)]
    result = [0 for  i in range(len(array))]

    for j in range(len(array)):
        cnt[array[j]] += 1

    for i in range(1, max(array)+1):
        cnt[i] += cnt[i-1]

    for j in reversed(range(len(array))):
        result[cnt[array[j]]-1] = array[j]
        cnt[array[j]] -= 1

    return result

n = int(input())
numbers = list(map(int, input().split()))
print(' '.join(map(str, counting_sort(numbers))))
