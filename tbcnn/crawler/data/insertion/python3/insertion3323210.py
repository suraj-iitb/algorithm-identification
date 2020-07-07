def insertion_sort(a):
    for i in range(1,len(a)):
        key = a[i]
        j = i-1
        while j >= 0 and a[j] > key:
            a[j+1] = a[j]
            j = j-1
        a[j+1] = key
        print(*a,sep=' ')
    return a


if __name__ == '__main__':
    n = input()
    a = list(map(int,input().split()))
    print(*a,sep=' ')
    insertion_sort(a)
