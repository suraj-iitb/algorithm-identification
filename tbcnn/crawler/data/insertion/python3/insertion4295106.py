def main():
    n = int(input())
    a = list(map(int,input().split()))
    for i in range(0,n):
        v = a[i]
        j = i-1
        while j>=0 and a[j]>v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        print (' '.join(map(str,a)))

if __name__ == '__main__':
    main()

