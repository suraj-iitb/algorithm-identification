def insertion_sort(l):
    for i in range(1, len(l)):
        tmp = l[i]
        j = i - 1
        while j >= 0 and l[j] > tmp:
            l[j+1] = l[j]
            j -= 1
        l[j+1] = tmp
        print(' '.join(map(str, l)))
    return l



if __name__ == '__main__':
    N = int(input())
    l = list(map(int, input().split()))

    print(' '.join(map(str, l)))
    insertion_sort(l)

