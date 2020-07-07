def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    
    count = 0

    flag = True
    while flag:
        flag = False
        for j in range(n-1, 0, -1):
            if a[j] < a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                flag = True
                count += 1
    
    print(*a)
    print(count)

if __name__ == '__main__':
    main()
