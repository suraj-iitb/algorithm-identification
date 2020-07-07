def bubble_sort(a):
    res = 0
    for i in range(len(a)):
        for j in range(len(a)-1, i, -1):
            if a[j-1] > a[j]:
                a[j], a[j-1] = a[j-1], a[j]
                res += 1
    return res

def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = bubble_sort(a)
    print(' '.join(map(str, a)))
    print(ans)

if __name__ == '__main__':
    main()
