def selectionsort(n,a):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj = j
        if i != minj:
            a[i], a[minj] = a[minj], a[i]
            count += 1
    return a, count

if __name__ == '__main__':
    n = int(input())
    a = [int(x) for x in input().split()]
    a, count = selectionsort(n,a)
    print(' '.join(map(str, a)))
    print(count)
