def bubble_sort(l):
    cnt = 0
    i = 0
    while i <=  len(l) - 1:
        for j in range(len(l) - 1, i, -1):
            if l[j-1] > l[j]: # Swap
                tmp = l[j]
                l[j] = l[j-1]
                l[j-1] = tmp
                cnt += 1
        i += 1
    return l, cnt

if __name__ == '__main__':
    N = int(input())
    l = list(map(int, input().split()))

    sl, cnt = bubble_sort(l)
    print(' '.join(map(str, sl)))
    print(cnt)

