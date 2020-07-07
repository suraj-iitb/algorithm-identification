def bubble_sort(args):
    count = 0
    result = args[:]
    l = len(result) - 1
    for i in range(0, l):
        for j in range(l, i, -1):
            if (result[j] < result[j-1]):
                result[j], result[j-1] = result[j-1], result[j]
                count += 1
    return result, count

if __name__ == '__main__':
    n = int(input())
    args = list(map(int, input().split()))[:n]
    r, c = bubble_sort(args)
    print(' '.join(map(str, r)))
    print(c)

