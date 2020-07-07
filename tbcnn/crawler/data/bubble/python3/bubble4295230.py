def main():
    n = int(input())
    a = list(map(int,input().split()))
    c = 0
    for i in range(n-1):
        for j in range(n-1,i,-1):
            if a[j] < a[j-1]:
                a[j],a[j-1] = a[j-1],a[j]
                c+=1
    print(' '.join(map(str,a)))
    print(c)


if __name__ == '__main__':
    main()

