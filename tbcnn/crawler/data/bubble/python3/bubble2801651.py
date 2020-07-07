def bubble_sort(l):
    num = 0
    for index in range(len(l)):
        for low in range(len(l)-1, index, -1):
            if l[low] < l[low-1]:
                l[low], l[low-1] = l[low-1], l[low]
                num += 1

    return (l, num)
if __name__ == '__main__':
    n = int(input())
    l = list(map(int,input().split()))
    lsorted, num = bubble_sort(l)
    print(" ".join(list(map(str,lsorted))))
    print(num)
